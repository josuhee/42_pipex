/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:27:52 by sujo              #+#    #+#             */
/*   Updated: 2021/06/24 21:42:30 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char *envp[])
{
	char *path;
	char **ret;

	while (*envp)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
		{
			path = *envp;
			break ;
		}
		envp++;
	}
	path = ft_substr(path, 5, ft_strlen(path) - 5);
	ret = ft_split(path, ':');
	free(path);
	return (ret);
}

void	child_process(t_cmd cmd, int *fd, char *file)
{
	int		idx;
	char	*tmp;

	idx = 0;
	redirect_in(file);
	connect_pipe(fd, STDOUT_FILENO);
	while (cmd.path[idx])
	{
		tmp = ft_strjoin(cmd.path[idx], cmd.argv[0]);
		execve(tmp, cmd.argv, cmd.envp);
		free(tmp);
		idx++;
	}
}

void	parent_process(int *fd, char *file)
{
	char	buffer[31];
	int		size;

	redirect_out(file);
	connect_pipe(fd, STDIN_FILENO);
	while ((size = read(STDIN_FILENO, buffer, 30)) > 0)
	{
		buffer[size] = '\0';
		write(STDOUT_FILENO, buffer, size);
	}
}
