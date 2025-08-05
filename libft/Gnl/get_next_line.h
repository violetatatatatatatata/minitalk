/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:53:12 by epascual          #+#    #+#             */
/*   Updated: 2024/12/13 21:06:02 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char			*ft_free_strjoin(char *save, char *tmp);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(char *s, char c);
unsigned long	ft_strlen(const char *str);
void			*ft_calloc(unsigned long nelem, unsigned long elsize);
char			*crealinea(char *s);
char			*guardaresto(char *s);
char			*lector(int fd, char *stash);
char			*get_next_line(int fd);
#endif
