/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:15:09 by bkiziler          #+#    #+#             */
/*   Updated: 2022/10/17 17:55:45 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r ;

	r = malloc (sizeof(t_list));
	if (r == NULL)
		return (0);
	r->content = (void *)content;
	r->next = NULL;
	return (r);
}
