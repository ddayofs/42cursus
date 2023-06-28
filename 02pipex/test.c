#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// int main(int argc, char *argv[])
// {
// 	(void )argv;
// 	printf("argc == %d\n", argc);	
// }

int main()
{
	int **fds;
	int	argc = 5;
	fds = (int **)malloc(sizeof(int *) * argc);
	for (int i = 0; i < argc; i++)
		fds[i] = (int *)malloc(sizeof(int) * 2);
	for (int i = 0; i < argc; i++)
	{
		pipe(fds[i]);
		for (int j = 0; j < 2; j++)
			printf("fds[%d][%d] == %d\n", i, j, fds[i][j]);
	}
}