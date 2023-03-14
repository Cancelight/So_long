/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:07:56 by bkiziler          #+#    #+#             */
/*   Updated: 2022/11/09 19:55:20 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;

	cp = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cp == NULL)
		return (0);
	ft_strlcpy(cp, s1, ft_strlen(s1) + 1);
	return (cp);
}
