#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int redirect_out(const char *file)
{
	int fd;
	fd = open(file, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

void connect_pipe(int fd[], int io)
{
	dup2(fd[io], io);
	close(fd[0]);
	close(fd[1]);
}

int main(int argc, char *argv[])
{
	pid_t pid;
	int fd[2];
	char *new_argv[]={"cat", NULL};
	
	pipe(fd);
	pid = fork();
	if (pid > 0)
	{
		redirect_in(argv[1]);
		connect_pipe(fd, STDOUT_FILENO);
		execve("/bin/cat", new_argv, 0);
	}
	else if (pid == 0)
	{
		char buffer[31];
		int size=read(fd[0], buffer, 30);
		buffer[size] = '\0';
		redirect_out(argv[2]);
		write(STDOUT_FILENO, buffer, size);
	}
	else
	{
		printf("fork error\n");
		return (1);
	}
	return (0);
}
