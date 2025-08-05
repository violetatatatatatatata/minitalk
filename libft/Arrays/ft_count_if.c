/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:07:39 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:48:15 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]))
		{
			count++;
		}
		i++;
	}
	return (count);
}
