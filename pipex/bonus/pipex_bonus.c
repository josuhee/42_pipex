/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:27:48 by sujo              #+#    #+#             */
/*   Updated: 2021/06/24 22:18:08 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int		redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int		redirect_out(const char *file)
{
	int fd;

	fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

void	connect_pipe(int fd[], int io)
{
	dup2(fd[io], io);
	close(fd[0]);
	close(fd[1]);
}

void	func(t_cmd cmd, char *infile, char *output)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		child_process(cmd, fd, infile);
		perror(cmd.argv[0]);
		exit(9);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) != 0)
			exit(1);
		parent_process(fd, output);
	}
	else
	{
		perror("fork");
		exit(1);
	}
}

void	pipex(int argc, char *argv[], char *envp[])
{
	int		idx;
	t_cmd	cmd;

	cmd.path = get_path(envp);
	cmd.envp = NULL;
	idx = 2;
	while (idx < argc - 1)
	{
		cmd.argv = ft_split_sp(argv[idx], ' ');
		if (idx == 2)
			func(cmd, argv[1], argv[argc - 1]);
		else
			func(cmd, argv[argc - 1], argv[argc - 1]);
		go_free_split_sp(cmd.argv);
		idx++;
	}
	go_free_split_sp(cmd.path);
}
