/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:16:58 by bkiziler          #+#    #+#             */
/*   Updated: 2022/11/15 19:08:34 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nback;
	void	*data;

	nback = NULL;
	if (!lst || !f | !del)
		return (nback);
	while (lst != NULL)
	{
		data = (*f)(lst->content);
		if (!data)
		{
			del(data);
			ft_lstclear(&nback, del);
			return (NULL);
		}
		ft_lstadd_back(&nback, ft_lstnew(data));
		lst = lst->next;
	}
	return (nback);
}
