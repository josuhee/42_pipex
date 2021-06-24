/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:50:29 by sujo              #+#    #+#             */
/*   Updated: 2021/05/06 13:21:03 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;
	t_list *tmp;

	ptr = *lst;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
