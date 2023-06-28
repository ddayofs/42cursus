/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:10:22 by donglee2          #+#    #+#             */
/*   Updated: 2023/06/28 13:23:13 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// // for bonus
// int	**make_arr_bonus(int argc, int ***fds)
// {
// 	int	i;

// 	*fds = (int **)malloc(sizeof(int *) * (argc - 3));
// 	if (!*fds)
// 		exit (1);
// 	i = -1;
// 	while (++i <= argc - 3)
// 	{
// 		*fds[i] = (int *)malloc(sizeof(int) * 2);
// 		if (!*fds[i])
// 			exit(1);
// 	}
// 	i = -1;
// 	while (++i <= argc - 3)
// 		pipe(*fds[i]);
// 	return (*fds);
// }

int main(int argc, char *argv[], char **envp)
{
	int	pid;
	int	fds[2];
	int	fd;
	// chk list-> func()
	//1. valid instr input by chking whether instr input is in instr dir
	//2. valid args num
	//3. find out num of args & num of pipes
	pipe(fds[2]);

	fd = open("file1", O_RDONLY);
	if (fd == -1)
		exit(1);
	dup2(fd, 0);
	close(fd);
	while (2)
	{
		pid = fork();
		if (pid == 0)
		{
			if(i == 0){

			}
			close(fds[0]);
			dup2(fds[1], STDOUT_FILENO);
			close(fds[1]);
			char *argv = {"cat", NULL};
			execvp(argv[1], argv);

			else if (i == 1)
			{

			}
		}
	}

	pid = fork();
	if (pid == 0)
	{

	}
	else
	{

	}
}

// #include <unistd.h>
// #include <sys/wait.h>
// #include <stdio.h>
// #include <stdlib.h>

int main(int argc, char *argv[])
{
	int fds[2];			// an array that will hold two file descriptors
	pipe(fds);			// populates fds with two file descriptors
	pid_t pid = fork(); // create child process that is a clone of the parent

	if (pid == 0)
	{										   // if pid == 0, then this is the child process
		dup2(fds[0], STDIN_FILENO);			   // fds[0] (the read end of pipe) donates its data to file descriptor 0
		close(fds[0]);						   // file descriptor no longer needed in child since stdin is a copy
		close(fds[1]);					   // file descriptor unused in child
		char *argv[] = {(char *)"sort", NULL}; // create argument vector
		if (execvp(argv[0], argv) < 0)
			exit(0); // run sort command (exit if something went wrong)
	}

	// if we reach here, we are in parent process
	close(fds[0]); // file descriptor unused in parent
	const char *words[] = {"pear", "peach", "apple"};

	// write input to the writable file descriptor so it can be read in from child:
	size_t numwords = sizeof(words) / sizeof(words[0]);
	for (size_t i = 0; i < numwords; i++)
	{
		dprintf(fds[1], "%s\n", words[i]);
	}

	// send EOF so child can continue (child blocks until all input has been processed):
	close(fds[1]);

	int status;
	pid_t wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting
	return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}
