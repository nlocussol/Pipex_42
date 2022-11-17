/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 00:00:35 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 00:32:07 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*stock_lst;

	if (f == NULL || del == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	stock_lst = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		stock_lst->next = ft_lstnew(f(lst->content));
		if (stock_lst->next == NULL)
		{
			ft_lstclear(&stock_lst, del);
			return (NULL);
		}
		stock_lst = stock_lst->next;
		lst = lst->next;
	}
	return (new_lst);
}
