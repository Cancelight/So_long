/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:16:48 by bkiziler          #+#    #+#             */
/*   Updated: 2022/10/18 15:36:11 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cnext;

	if (!lst || !del || !*lst)
		return ;
	cnext = (*lst);
	while (cnext != (NULL))
	{
		cnext = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = cnext;
	}
}
