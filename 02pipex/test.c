#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// int main(int argc, char *argv[])
// {
// 	(void )argv;
// 	printf("argc == %d\n", argc);	
// }


#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {
// 	int fds[2];			// an array that will hold two file descriptors
// 	pipe(fds);			// populates fds with two file descriptors
// 	pid_t pid = fork(); // create child process that is a clone of the parent

// 	if (pid == 0)
// 	{										   // if pid == 0, then this is the child process
// 		dup2(fds[0], STDIN_FILENO);			   // fds[0] (the read end of pipe) donates its data to file descriptor 0
// 		close(fds[0]);						   // file descriptor no longer needed in child since stdin is a copy
// 		close(fds[1]);						   // file descriptor unused in child
// 		char *argv[] = {(char *)"sort", NULL}; // create argument vector
// 		if (execvp(argv[0], argv) < 0)
// 			exit(0); // run sort command (exit if something went wrong)
// 	}

// 	// if we reach here, we are in parent process
// 	close(fds[0]); // file descriptor unused in parent
// 	const char *words[] = {"pear", "peach", "apple"};
// 	// write input to the writable file descriptor so it can be read in from child:
// 	size_t numwords = sizeof(words) / sizeof(words[0]);
// 	for (size_t i = 0; i < numwords; i++)
// 	{
// 		dprintf(fds[1], "%s\n", words[i]);
// 	}

// 	// send EOF so child can continue (child blocks until all input has been processed):
// 	close(fds[1]);

// 	int status;
// 	pid_t wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting
// 	return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
// }

// int main()
// {
// 	int **fds;
// 	int	argc = 5;
// 	fds = (int **)malloc(sizeof(int *) * argc);
// 	for (int i = 0; i < argc; i++)
// 		fds[i] = (int *)malloc(sizeof(int) * 2);
// 	for (int i = 0; i < argc; i++)
// 	{
// 		pipe(fds[i]);
// 		for (int j = 0; j < 2; j++)
// 			printf("fds[%d][%d] == %d\n", i, j, fds[i][j]);
// 	}
// }


// return value of pipe()
// int main()
// {
// 	int	fds[2];
// 	int fds2[2];
// 	int	fail[1];
// 	int	fd_num;
// 	int dup_num;

// 	fd_num = pipe(fds);
// 	printf("fd_num == %d\nfds[0] == %d\nfds[1] == %d\n", fd_num, fds[0], fds[1]);
// 	dup_num = dup2(fds[0], 1);
// 	printf("dup_num == %d\n", dup_num);
// 	// fd_num = pipe(fds2);
// 	// printf("fd_num == %d\nfds2[0] == %d\nfds2[1] == %d\n", fd_num, fds2[0], fds2[1]);
// 	// fd_num = pipe(fail);
// 	// printf("fd_num == %d\nfail[0] == %d\n", fd_num, fail[0]);
// }
// }


// int	main(int argc, char *argv[], char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	while(*envp)
// 	{
// 		if (*(*envp + 1)== 'A' && *(*envp + 2) == 'T')
// 			printf("%s\n", *envp + 5);
// 		envp++;
// 	}
// }

// //access 함수 예제
// #include <unistd.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     if (access(argv[1], X_OK) != 0)
//         perror("파일이 존재하지 않음 : ");
//     else
//         printf("파일 존재함\n");
// }

// //exit(1) 언제 사용할 수 있을까
// void	leak()
// {
// 	system("leaks a.out");
// }


// void	test()
// {
// 	char *tmp;

// 	tmp = (char *)malloc(sizeof(char));
// 	exit(1);
// }

// void	test2()
// {
// 	char *tmp;

// 	tmp = (char *)malloc(sizeof(char));
// 	if (tmp)
// 		exit(1);
// }

// int	main()
// {
// 	atexit(leak);
// 	test2();
// 	test();
// 	exit(1);
// }

// //split_test-----------------------------------------------------------------------------------------


static int	words_count(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	if (str[0] == 0)
		return (0);
	if (str[++i] != c)
		count++;
	while (str[++i])
		if (str[i - 1] == c && str[i] != c)
			count++;
	return (count);
}

static char	*copy_str(char const *str, char c, int *s_idx)
{
	char	*ret2_str;
	int		word_len;
	int		j;

	word_len = 0;
	j = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	*s_idx += word_len;
	ret2_str = (char *)malloc (sizeof(char) * (word_len + 1));
	if (ret2_str == NULL)
		return (NULL);
	while (j < word_len)
	{
		ret2_str[j] = str[j];
		j++;
	}
	ret2_str[j] = 0;
	return (ret2_str);
}

static char	**ft_freeall(char **ret_str)
{
	int	idx;

	idx = -1;
	while (ret_str[++idx])
		free(ret_str[idx]);
	free(ret_str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret_str;
	int		i;
	int		ret_str_i;

	ret_str = (char **)malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (ret_str == NULL)
		return (NULL);
	i = 0;
	ret_str_i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
		{
			ret_str[ret_str_i] = copy_str(&s[i], c, &i);
			if (ret_str[ret_str_i] == NULL)
				return (ft_freeall(ret_str));
			ret_str_i++;
		}
	}
	ret_str[ret_str_i] = NULL;
	return (ret_str);
}
int main()
{
	char str[20] = "orange is delicious";
	char	**split_str;
	char	*tmp;

	split_str = ft_split(str, ' ');
	tmp = split_str[0];
	for(int i = 0; split_str[i]; i++)
		free(split_str[i]);
	free(split_str);
	printf("%s\n", tmp);
}
--------------------------------------------------------------------------------------

// int main(int argc, char*argv[])
// {
// 	(void)argv;
// 	printf("%d\n", argc);
// }

// #include <fcntl.h>
// #include <unistd.h>

// int main() {
//     int fd = open("tmp.txt", O_WRONLY);
//     if (fd == -1) {
//         // 파일 열기 실패
//         return 1;
//     }

//     const char* data = "Hello, World!\n\n\n";
//     write(fd, data, strlen(data));

//     close(fd);
//     return 0;
// }


// #include "pipex.h"

// not yet freed : tmp( == split_str[0])
char	*extract_cmd(char *str)
{
	char	**split_str;
	char	*tmp;
	int		i;

	split_str = ft_split(str, ' ');
	if (!split_str)
		exit(1);
	tmp = split_str[0];
	i = 0;
	free_all_splits(split_str);
	return (tmp);
}

char	*find_path(char **envp)
{
	while (*envp)
	{
		if (*(*envp + 1) == 'A' && *(*envp + 2) == 'T')
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

//not yet freed : path
char	*add_cmd_to_path(char *path, char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		exit(1);
	free(path);
	path = ft_strjoin(tmp, cmd);
	free (tmp);
	if (!path)
		exit(1);
	return (path);
}

void	free_all_splits(char **split_path)
{
	int	i;

	i = 0;
	while (split_path[++i])
		free(split_path[i]);
	free(split_path);
}

// perror(cmd);//perror 번호. 추가 ?? 에러메시지 추ㅏㄱ 가능?
// zsh: command not found: <user input>
// vs <user input>: No such file or directory
// what about options????
// implementation : error message
char	*find_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	**split_path;
	int		i;
	char	*ret;

	path = find_path(envp);
	if (!path)
		exit(1);
	split_path = ft_split(path, ':');
	if (!split_path)
		exit (1);
	i = -1;
	while (split_path[++i])
	{
		split_path[i] = add_cmd_to_path(split_path[i], cmd);
		if (access(split_path[i], X_OK) == 0)
		{
			ret = split_path[i];
			free_all_splits(split_path);
			printf("%s\n", ret);
			return (ret);
		}
	}
	return (NULL);
}
int main(int argc, char *argv[], char **envp)
{
	printf("%s\n", find_cmd_path(extract_cmd(argv[1]), envp));
}