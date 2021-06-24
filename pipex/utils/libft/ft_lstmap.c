/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:27:27 by sujo              #+#    #+#             */
/*   Updated: 2021/05/06 22:10:17 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	go_free(t_list *lst, void (*del)(void *))
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		del(tmp->content);
		free(tmp);
	}
	lst = NULL;
}

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list *ret;
	t_list *start;
	t_list *new_node;

	if (!l)
		return (0);
	new_node = ft_lstnew(f(l->content));
	if (!new_node)
		return (0);
	ret = new_node;
	start = ret;
	l = l->next;
	while (l)
	{
		new_node = ft_lstnew(f(l->content));
		if (!new_node)
		{
			go_free(ret, d);
			return (NULL);
		}
		start->next = new_node;
		start = start->next;
		l = l->next;
	}
	return (ret);
}
