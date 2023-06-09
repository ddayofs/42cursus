#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
// int main(int argc, char *argv[])
// {
// 	(void )argv;
// 	printf("argc == %d\n", argc);	
// }

#include <sys/types.h>
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

// int	main()
// {
// 	int fd1;
// 	int fd2;

// 	fd1 = open("file1", O_RDONLY);
// 	fd2 = open("file1", O_WRONLY);

// 	printf("%d\n", fd1);
// 	printf("%d\n", fd2);
// 	printf("%d\n", dup(fd1));
// 	printf("%d\n", dup2(fd2, fd1));
	
// }

// void print_argv1_again(char **argv)
// {
// 	printf("%s\n", argv[1]);
// }
// void print_argv1(char *argv[])
// {
// 	printf("%s\n", argv[1]);
// }

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	print_argv1(argv);	
// 	system("leaks a.out");
// }

int main()
{
	int		status;
	pid_t	pid;

	for(int i = 0; i < 3; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("i'm child proc\nchild pid is %d\n\n", getpid());
			exit(0);
		}
		else
		{
			printf("i'm parent proc\nparent pid is %d\n\n", getpid());
		}
	}
	for (int k = 0; k < 3; k++)
	{
		if(pid == waitpid(-1, &status, 0))
			exit(WEXITSTATUS(status));
	}
}