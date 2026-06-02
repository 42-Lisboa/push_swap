/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:52:22 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/02 15:09:39 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	sort_two(t_array *data);
static int	sort_three(t_array *data);
static int	sort_five(t_array *data, t_array *data_b);

int	swap_small_stack(t_array *data, t_array *data_b)
{
	if (data->size == 2)
		return (sort_two(data));
	else if (data->size == 3)
		return (sort_three(data));
	else if (data->size <= 5)
		return (sort_five(data, data_b));
}
// 19. Function to dispatch the small stack cases 

static int	sort_two(t_array *data)
{
	int	head;
	int	tail;
	int	counter;

	counter = 0;
	head = data->values[data->head];
	tail = data->values[(data->head + 1) % data->capacity];
	if (head > tail)
		counter += sa(data);
	return (counter);
}
// 37. If head is bigger than tail, just do regular swap

static int	sort_three(t_array *data)
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
		counter += sa(data);
	head = data->values[data->head];
	middle = data->values[(data->head + 1) % data->capacity];
	if (head > tail && tail > middle)
		counter += ra(data);
	if (head > middle && middle > tail)
		counter += sa(data);
	head = data->values[data->head];
	middle = data->values[(data->head + 1) % data->capacity];
	if (middle > head && head > tail)
		counter += rra(data);
	if (tail > head && head > middle)
		counter += sa(data);
	return (counter);
}
// 48. i.e. 1 3 2 sa ra
// 52. i.e. 3 1 2 ra
// 54. i.e. 3 2 1 sa rra
// 58. i.e. 2 3 1 rra
// 60. i.e. 2 1 3 sa
// 53. After each swap (sa) operation, we must re-declare head and middle

static int	sort_five(t_array *data, t_array *data_b)
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
				counter += ra(data);
		}
		else
		{
			while (i++ < data->size - moves)
				counter += rra(data);
		}
		counter += pb(data, data_b);
	}
	counter += sort_three(data);
	counter += pa(data_b, data);
	counter += pa(data_b, data);
	return (counter);
}
// 78. Until the stack A is not size three, we must find smallest numbers
// 92. Then we push them to stack B (pb);
// 94. Sort the three numbers on stack A;
// 95. Push back smallest numbers from stack B;
/* 
static void print_stack(char *name, t_array *s)
{
    printf("%s: ", name);
    for (int i = 0; i < s->size; i++)
    {
        int idx = (s->head + i) % s->capacity;
        printf("%d ", s->values[idx]);
    }
    printf("\n");
}

int main(void)
{
	t_array data;
	int	number[] = {2, 1, 3};
	data.values = number;
	data.size = 3;
	data.capacity = 3;
	data.head = 0;   

    sort_three(&data);
    print_stack("Stack A: ", &data);
} */
