/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:38:41 by sujo              #+#    #+#             */
/*   Updated: 2021/06/23 15:45:35 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_copy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 + len2 == 0)
		return (ft_strdup(""));
	result = (char *)malloc(len1 + len2 + 2);
	if (!result)
		return (0);
	ptr = result;
	ptr = ft_str_copy(result, (char *)s1);
	*ptr = '/';
	ptr++;
	ptr = ft_str_copy(ptr, (char *)s2);
	return (result);
}
