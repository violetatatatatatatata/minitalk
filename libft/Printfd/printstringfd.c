/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstringfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:21:16 by epascual          #+#    #+#             */
/*   Updated: 2025/02/12 15:49:47 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	printstringfd(int fd, char const *s)
{
	int	res;

	res = 0;
	if (s == NULL)
	{
		res += printstringfd(fd, "(null)");
		return (res);
	}
	while (*s != 0)
	{
		res += printcharfd(fd, *s);
		s++;
	}
	return (res);
}
//int main(){printstring("Comprovacion");printf("Comprovacion");}
