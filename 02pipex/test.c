#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
}