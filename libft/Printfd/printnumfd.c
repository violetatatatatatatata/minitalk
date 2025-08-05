/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:06:11 by epascual          #+#    #+#             */
/*   Updated: 2025/02/27 13:02:14 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	printcharfd(int fd, char a)
{
	if (write(fd, &a, 1) < 1)
		return (0);
	return (1);
}

unsigned int	strilen(char *s)
{
	unsigned int	ret;

	ret = 0;
	while (*s)
	{
		ret++;
		s++;
	}
	return (ret);
}

int	printnumfd(int fd, long n, char *base)
{
	int		b;
	long	num;
	int		res;

	res = 0;
	b = strilen(base);
	num = (long)n;
	if (num < 0)
	{
		printcharfd(fd, '-');
		num = -num;
		res++;
	}
	if (num >= b)
	{
		res += printnumfd(fd, num / b, base);
		res += printnumfd(fd, num % b, base);
	}
	else
	{
		printcharfd(fd, base[num]);
		res++;
	}
	return (res);
}

int	printunumfd(int fd, unsigned int n, char *base)
{
	unsigned int	b;
	unsigned int	num;
	int				res;

	res = 0;
	b = strilen(base);
	num = (unsigned long)n;
	if (num >= b)
	{
		res += printunumfd(fd, num / b, base);
		res += printunumfd(fd, num % b, base);
	}
	else
	{
		printcharfd(fd, base[num]);
		res++;
	}
	return (res);
}
//int main(){printnum(-123, "0123456789");printf("\n%d\n",-123);return(0);}
