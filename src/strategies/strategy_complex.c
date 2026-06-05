/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:41:06 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/05 16:15:59 by jcas1808         ###   ########.fr       */
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
				break;
			}
			j++;
		}
		i++;
	}
}

/* Radix Sort is a linear sorting algorithm (for fixed length digit counts) that sorts elements by processing them digit by digit.

It repeatedly distributes the elements into buckets based on each digit's value. 
By repeatedly sorting the elements by their significant digits, from the least significant to the most significant, it achieves the final sorted order.
We use a stable algorithm like Counting Sort to sort the individual digits so that the overall algorithm remains stable.

To perform radix sort on the array [170, 45, 75, 90, 802, 24, 2, 66], we follow these steps:

Step 1: Find the largest element, which is 802. It has three digits, so we will iterate three times.

Step 2: Sort the elements based on the unit place digits (X=0).  

Step 3: Sort the elements based on the tens place digits. (X=1).  

Step 4: Sort the elements based on the hundreds place digits. */