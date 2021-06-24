/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:26:26 by sujo              #+#    #+#             */
/*   Updated: 2021/06/24 22:12:29 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../../utils/libft/libft.h"

typedef struct	s_cmd
{
	char **path;
	char **argv;
	char **envp;
}				t_cmd;

void			pipex(int argc, char *argv[], char *envp[]);
char			**ft_split_sp(char const *s, char c);
char			**go_free_split_sp(char **str);
char			**get_path(char *envp[]);

int				redirect_in(const char *file);
int				redirect_out(const char *file);
void			connect_pipe(int fd[], int io);

void			child_process(t_cmd cmd, int *fd, char *file);
void			parent_process(int *fd, char *file);

#endif
