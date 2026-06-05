/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:59:25 by jcas1808          #+#    #+#             */
/*   Updated: 2026/06/05 14:59:36 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int compute_disorder(t_array *data)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;
	
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	j = 0;
	while (i < data->size)
	{
		while (j < data->size)
		{
			total_pairs++;
			if (data->values[i] > data->values[j])
				mistakes += 1;
		}
	}
	return (mistakes / total_pairs);
}
