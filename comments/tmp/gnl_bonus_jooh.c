\#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <stdio.h>

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
	// t_list	*tmp;

	// if (!lst || !*lst || !del)
	// 	return ;
	// while (*lst)
	// {
	// 	tmp = (*lst)->next;
	// 	del((*lst)->save);
	// 	free(*lst);
	// 	*lst = tmp;
	// }
// }

void	rm_node(int fd, t_list **head_ptr)
{
	t_list	*cur_node;
	t_list	*prev_node;

	cur_node = *head_ptr;
	if (cur_node->fd_num == fd)
	{
		*head_ptr =	cur_node->next;
		free(cur_node->save);
		free(cur_node);
		return ;
	}
	while (cur_node)
	{
		if (cur_node->fd_num == fd)
			break;
		prev_node = cur_node;
		cur_node = cur_node->next;
	}
	prev_node->next = cur_node->next;
	free(cur_node->save);
	free(cur_node);
}

t_list	*find_node(int fd, t_list **head_node_ptr)
{
	t_list	*cur_node;
	t_list	*new_node;

	cur_node = *head_node_ptr;//리스트의 시작인 head_node는 계속 static으로 주소가 유지되어야 함수 호출할 때마다 리스트를 순회할 수 있다.
	while (cur_node)
	{
		if (cur_node->fd_num == fd)//리스트에 해당 fd 구조체 존재하면 해당 노드 반환 후, 함수 끝.
			return (cur_node);
		// if (!(cur_node->next))//리스트의 마지막 노드까지 해당 fd 구조체 찾지 못하고 반복문 탈출. tmp는 리스트의 마지막 노드인 상태.
		// 	break;
		cur_node = cur_node->next;
	}
	//fd 찾지 못하면..혹은 head_node가 null이라면 새로운 노드가 만들고 리스트에 붙여줘야 한다.
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		//리스트 삭제 함수 삽입 필요... 없네??????
		return (NULL);
	//lstadd_back
	// new_node->next = NULL;
	new_node->next = *head_node_ptr;
	new_node->save = NULL;
	new_node->fd_num = fd;
	// if (!cur_node)
	// 	*head_node_ptr = new_node;
	// else
	// 	cur_node->next = new_node;
	return (new_node);
}


char	*cut_line(char **save)
{
	char	*ret_line;
	char	*tmp;
	ssize_t	idx;

	idx = ft_strchr_idx(*save, '\n');
	if (idx == -1)
		idx = ft_strchr_idx(*save, '\0');
	ret_line = ft_substr(*save, 0, idx + 1);
	if (!ret_line)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	tmp = ft_substr(*save, idx + 1, ft_strlen(*save));
	free(*save);
	if (!tmp)
	{
		*save = NULL;
		free (ret_line);
		return (NULL);
	}
	*save = tmp;
	return (ret_line);
}

int	read_chk_add_line(int read_ret, char **save, char *buff)
{
	char	*tmp;

	if (read_ret == -1 || (read_ret == 0 && !(**save)))//후자의 경우 해당 노드 삭제 후 끊어진 노드를 이어준다.(해당 노드 다 읽었기 때문)
	{
		free(*save);
		*save = NULL;
		return (1);
	}
	buff[read_ret] = '\0';
	if (read_ret == 0 && *save)
		return (-1);
	tmp = ft_strjoin(*save, buff);
	free (*save);
	*save = (NULL);
	if (!tmp)
		return (1);
	*save = tmp;
	return (0);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static t_list	*head_node;
	t_list			*cur_node;
	int				tmp;

	cur_node = find_node(fd, &head_node);
	if (!(cur_node->save))
		cur_node->save = ft_strdup("");
	if (!(cur_node->save))
		return (NULL);
	while (ft_strchr_idx(cur_node->save, '\n') < 0)
	{
		tmp = read_chk_add_line(read(fd, buff, BUFFER_SIZE), &(cur_node->save), buff);
		if (tmp == -1)
			break;
		if (tmp)
		{
			rm_node(fd, &head_node);
			return (NULL);
		}
	}
	return (cut_line(&(cur_node->save)));
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	// int	i = 0;

// 	// while (i < 40)
// 	// {
// 	// 	char *new_line = get_next_line(fd);
// 	// 	printf("%s", new_line);
// 	// 	i++;
// 	// }
// 	char *new_line = get_next_line(fd);
// 	while (new_line)
// 	{
// 		printf("%s", new_line);
// 		free(new_line);
// 		new_line = get_next_line(fd);
// 	}
// 	printf("%s\n", new_line);
// 	return (0);
// }