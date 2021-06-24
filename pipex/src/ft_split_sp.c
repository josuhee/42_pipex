/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:32:55 by sujo              #+#    #+#             */
/*   Updated: 2021/06/24 20:21:34 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int			str_size(const char *str, char c)
{
	size_t	size;
	char	ch;
	int		flag;

	size = 0;
	flag = 1;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
		{
			ch = *str++;
			while (*str != ch)
				str++;
		}
		if (flag && *str != c)
		{
			size++;
			flag = 0;
		}
		if (*str == c)
			flag = 1;
		str++;
	}
	return (size);
}

static char			*get_str_split(char const *s, char c, char c2)
{
	char		*result;
	const char	*ptr;
	size_t		length;

	ptr = s;
	length = 0;
	if (c2 == '\'' || c2 == '"')
	{
		c = c2;
		ptr++;
		s++;
	}
	while (*ptr && *ptr++ != c)
		length++;
	result = (char *)malloc(length + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s, length + 1);
	return (result);
}

char				**go_free_split_sp(char **str)
{
	size_t idx;

	idx = 0;
	while (str[idx])
		free(str[idx++]);
	free(str);
	return (0);
}

static const char	*func(const char *s, char c, char c2)
{
	if (c2 == '\'' || c2 == '"')
	{
		c = c2;
		s++;
	}
	while (*s && *s != c)
		s++;
	if (c2 == '\'' || c2 == '"')
		s++;
	return (s);
}

char				**ft_split_sp(char const *s, char c)
{
	char	**result;
	int		idx;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char*) * (str_size(s, c) + 1));
	if (!result)
		return (0);
	idx = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			result[idx] = get_str_split(s, c, *s);
			if (!result[idx++])
				return (go_free_split_sp(result));
			s = func(s, c, *s);
		}
		else
			s++;
	}
	result[idx] = 0;
	return (result);
}
