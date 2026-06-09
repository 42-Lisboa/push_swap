/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_small_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:41:25 by jcas1808          #+#    #+#             */
/*   Updated: 2026/06/09 16:47:41 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	sort_two(t_array *data, t_count *count_ops);
static int	sort_three(t_array *data, t_count *count_ops);
static int	sort_five(t_array *data, t_array *data_b, t_count *count_ops);

int	swap_small_stack(t_array *data, t_array *data_b, t_count *count_ops)
{
	if (data->size == 2)
		return (sort_two(data, count_ops));
	else if (data->size == 3)
		return (sort_three(data, count_ops));
	else if (data->size <= 5)
		return (sort_five(data, data_b, count_ops));
	return (0);
}
// 19. Function to dispatch the small stack cases

static int	sort_two(t_array *data, t_count *count_ops)
{
	int	head;
	int	tail;
	int	counter;

	counter = 0;
	head = data->values[data->head];
	tail = data->values[(data->head + 1) % data->capacity];
	if (head > tail)
		counter += sa(data, count_ops);
	return (counter);
}
// 37. If head is bigger than tail, just do regular swap

static int	sort_three(t_array *data, t_count *count_ops)
{
	int	head;
	int	middle;
	int	tail;
	int	counter;

	counter = 0;
	head = data->values[data->head];
	middle = data->values[(data->head + 1) % data->capacity];
	tail = data->values[(data->head + 2) % data->capacity];
	if (middle > tail && tail > head)
		counter += sa(data, count_ops);
	head = data->values[data->head];
	middle = data->values[(data->head + 1) % data->capacity];
	if (head > tail && tail > middle)
		counter += ra(data, count_ops);
	if (head > middle && middle > tail)
		counter += sa(data, count_ops);
	head = data->values[data->head];
	middle = data->values[(data->head + 1) % data->capacity];
	if (middle > head && head > tail)
		counter += rra(data, count_ops);
	if (tail > head && head > middle)
		counter += sa(data, count_ops);
	return (counter);
}
// 48. i.e. 1 3 2 sa ra
// 52. i.e. 3 1 2 ra
// 54. i.e. 3 2 1 sa rra
// 58. i.e. 2 3 1 rra
// 60. i.e. 2 1 3 sa
// 53. After each swap (sa) operation, we must re-declare head and middle

static int	sort_five(t_array *data, t_array *data_b, t_count *count_ops)
{
	int	moves;
	int	i;
	int	counter;

	counter = 0;
	while (data->size > 3)
	{
		moves = movements_to_smallest(data);
		i = 0;
		if (moves <= data->size / 2)
		{
			while (i++ < moves)
				counter += ra(data, count_ops);
		}
		else
		{
			while (i++ < data->size - moves)
				counter += rra(data, count_ops);
		}
		counter += pb(data, data_b, count_ops);
	}
	counter += sort_three(data, count_ops);
	counter += pa(data_b, data, count_ops);
	counter += pa(data_b, data, count_ops);
	return (counter);
}
// 78. Until the stack A is not size three, we must find smallest numbers
// 92. Then we push them to stack B (pb);
// 94. Sort the three numbers on stack A;
// 95. Push back smallest numbers from stack B;
