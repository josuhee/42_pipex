#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	int x;

	x = 0;

	//new process
	pid = fork();

	//parent process
	if (pid > 0)
	{
		x = 1;
		printf("Parent\tPID : %d, x : %d\n", getpid(), x);
	}
	//child process
	else if (pid == 0)
	{
		x = 2;
		printf("Child\tPID : %d, x : %d\n", getpid(), x);
	}
	//fork error
	else
	{
		printf("fork error\n");
		return (-1);
	}
	return (0);
}
