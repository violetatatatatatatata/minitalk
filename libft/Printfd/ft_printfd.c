/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:23:26 by epascual          #+#    #+#             */
/*   Updated: 2025/05/12 19:50:40 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

//Implemento como musl porque openbsd y glibc no me gustan tanto
//Restrict significa que este puntero solo puede ser leido
//A diferencia del printf real de musl no paso el stdout como parametro
int	ft_printfd(int fd, char const *p, ...)
{
	va_list	opc;
	int		ret;

	va_start(opc, p);
	ret = realprintfd(fd, p, opc);
	va_end(opc);
	return (ret);
}

void	checkerfd(int fd, int *ret, char check, va_list opc)
{
	if (check == 'c')
		*ret += printcharfd(fd, va_arg(opc, int));
	if (check == 's')
		*ret += printstringfd(fd, va_arg(opc, char *));
	if (check == 'p')
		*ret += printpointfd(fd, va_arg(opc, unsigned long long),
				"0123456789abcdef");
	if (check == 'd')
		*ret += printnumfd(fd, va_arg(opc, int), "0123456789");
	if (check == 'i')
		*ret += printnumfd(fd, va_arg(opc, int), "0123456789");
	if (check == 'u')
		*ret += printunumfd(fd, va_arg(opc, unsigned int), "0123456789");
	if (check == 'x')
		*ret += printunumfd(fd, va_arg(opc, unsigned int), "0123456789abcdef");
	if (check == 'X')
		*ret += printunumfd(fd, va_arg(opc, unsigned int), "0123456789ABCDEF");
	if (check == '%')
		*ret += printcharfd(fd, '%');
}

int	realprintfd(int fd, char const *p, va_list opc)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (p[i])
	{
		if (p[i] != '%')
			ret += printcharfd(fd, p[i]);
		else
		{
			i++;
			checkerfd(fd, &ret, p[i], opc);
		}
		i++;
	}
	return (ret);
}
//int main(){char *s="Probando";
//ft_printfd(2, "Prueba y %s%i%p", s,12,NULL);return (0);}
