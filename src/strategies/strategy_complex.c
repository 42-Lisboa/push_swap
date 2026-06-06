/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:41:06 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/06 15:53:35 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	indexation(t_array *src, int *sorted_copy)
{
	int	i;
	int	j;
	int	capacity_idx;

	i = 0;
	while (i < src->size)
	{
		j = 0;
		capacity_idx = (src->head + i) % src->capacity;
		while (j < src->size)
		{
			if (src->values[capacity_idx] == sorted_copy[j])
			{
				src->values[capacity_idx] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	get_max_bits(t_array *src)
{
	int	greatest_idx;
	int	max_bits;
	
	max_bits = 0;
	greatest_idx = src->size - 1;
	while (greatest_idx > 0)
	{
		greatest_idx >>= 1;
		max_bits++;
	}
	return (max_bits);
}
/* 
Radix Sort is a linear sorting algorithm (for fixed length digit counts)
that sorts elements by processing them digit by digit.

int strategy_complex(t_array *data, t_array *data_b)
{
    
} */
