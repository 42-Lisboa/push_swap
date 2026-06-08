/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:59:25 by jcas1808          #+#    #+#             */
/*   Updated: 2026/06/08 16:01:40 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static float	compute_disorder(t_array *data);

int	strategy_adaptive(t_array *data, t_array *data_b)
{
	float	disorder;

	disorder = compute_disorder(data);
	if (data->size <= 5)
		return (swap_small_stack(data, data_b));
	if (disorder < 0.2)
		return (strategy_simple(data, data_b));
	else if (disorder >= 0.2 && disorder < 0.5)
		return (strategy_medium(data, data_b));
	else if (disorder >= 0.5)
		return (strategy_complex(data, data_b));
	return (0);
}
// 21. For small stacks of 5 or fewer, use a dedicated small-stack handler;
// 23. Measure how disordered the stack currently is;
// 24. Nearly sorted stacks use the simple selection-based strategy;
// 26. Moderately disordered stacks use the medium bucket-based strategy;
// 28. Highly disordered stacks use the complex radix-based strategy;

static float	compute_disorder(t_array *data)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

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
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
// 53. Count every pair of elements in the stack as a candidate comparison;
// 55. Increment mistakes whenever an element is greater than a later one;
// 60. Return the ratio of inverted pairs over total pairs as a disorder score;
