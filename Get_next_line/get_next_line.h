/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:37:05 by bkiziler          #+#    #+#             */
/*   Updated: 2023/01/28 14:53:56 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
unsigned int	ft_strlen(char *ptr);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
char			*ft_strjoin(char *s1, char *s2);
char			*trim(char *red);
char			*apart_line(char *red);
char			*read_function(int fd, char *red);

#endif
