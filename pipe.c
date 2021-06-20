#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd[2];
	char buffer[30];
	pid_t pid;
	int state;

	if (pipe(fd) == -1)
	{
		printf("pipe error\n");
		exit(1);
	}

	pid = fork();

	if (pid > 0)
	{
		read(fd[0], buffer, 30);
		printf("Output of parent process: %s\n", buffer);
		write(fd[1], "Goob job\n", 26);
		sleep(2);
	}
	else if (pid == 0)
	{
		write(fd[1], "connect\n", 7);
		sleep(2);
		read(fd[0], buffer, 30);
		printf("Output of child process: %s\n", buffer);
	}
	else
	{
		printf("pipe error");
		exit(1);
	}

	return (0);
}

