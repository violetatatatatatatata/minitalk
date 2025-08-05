/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:04:20 by epascual          #+#    #+#             */
/*   Updated: 2025/06/12 15:02:14 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

long	ft_atoi(const char *n)
{
	long	res;
	int		i;
	int		neg;

	neg = 1;
	res = 0;
	i = 0;
	while ((n[i] >= '\t' && n[i] <= '\r') || n[i] == ' ')
		i++;
	if (n[i] == '-')
		neg = -1;
	if (n[i] == '+' || n[i] == '-')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
	{
		res = res * 10;
		res = res + n[i] - '0';
		i++;
		if (res * neg > 2147483647 || res * neg < -2147483648)
			break ;
	}
	return (neg * res);
}
