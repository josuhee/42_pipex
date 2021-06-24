/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:08:00 by sujo              #+#    #+#             */
/*   Updated: 2021/05/06 13:52:59 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->next = NULL;
	result->content = content;
	return (result);
}
