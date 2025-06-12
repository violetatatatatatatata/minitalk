/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:01:49 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:48:39 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	*ft_range(int min, int max)
{
	int	*range;
	int	iter;

	iter = min;
	if (min >= max)
	{
		return (0);
	}
	range = (int *)malloc(sizeof(int) * (max - min));
	if (range == 0)
		return (0);
	while (iter < max)
	{
		range[iter - min] = iter;
		iter++;
	}
	return (range);
}
