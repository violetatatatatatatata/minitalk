/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:26:27 by epascual          #+#    #+#             */
/*   Updated: 2025/02/17 14:52:30 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTFD_H
# define FT_PRINTFD_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

void			checkerfd(int fd, int *ret, char check, va_list opc);
int				realprintfd(int fd, char const *p, va_list opc);
int				ft_printfd(int fd, char const *print, ...);
int				printcharfd(int fd, char a);
int				printstringfd(int fd, char const *s);
int				printnumfd(int fd, long n, char *base);
int				printunumfd(int fd, unsigned int n, char *base);
int				printpointfd(int fd, unsigned long long n, char *base);
#endif
