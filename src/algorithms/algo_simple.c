/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/30 18:42:48 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	movements_to_smallest(t_array *data);

void	strategy_simple(t_array *data, t_array *data_b)
{
	int moves;
	int	i;

	while (data->size > 0)
	{
		moves = movements_to_smallest(data);
		i = 0;
		if (moves <= data->size / 2)
		{
			while (i++ < moves)
				ra(data);
		}
		else
		{
			while (i++ < data->size - moves)
				rra(data);
		}
		pb(data, data_b);
	}
	while (data_b->size > 0)
		pa(data_b, data);
}
// 42. Find logical position of smallest element;
// 46. If smallest is in first half, rotate forward;
// 49. Rotate until smallest reaches the top;
// 56. If smallest is in second half, rotate backward;
// 59. Use shortest path with reverse rotations;
// 65. Push smallest element to stack B;

int movements_to_smallest(t_array *data)
{
    int count;
    int count_moves;
    int smallest_val;
    int capacity_idx;

    smallest_val = data->values[data->head];
    count_moves = 0;
    count = 1;
    while (count < data->size)
    {
        capacity_idx = (data->head + count) % data->capacity;
        if (data->values[capacity_idx] < smallest_val)
        {
            smallest_val = data->values[capacity_idx];
            count_moves = count;
        }
        count++;
    }
    return (count_moves);
}
// 68. Start assuming first element is the smallest;
// 71. Loop through all logical positions;
// 76. Update smallest value when a smaller one is found;
// 26. Save the logical position of smallest value;
// 31. Return amount of moves to reach smallest element;
/* 
void print_stack(char *name, t_array *s)
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
	int	number[] = {2, 8, 1, 4, 9};
	data.values = number;
	data.size = 5;
	data.capacity = 6;
	data.head = 0;

	t_array data_b;
	int number_b[6] = {0};
	data_b.values = number_b;
	data_b.size = 0;
	data_b.capacity = 6;
	data_b.head = 0;
	
	
	// Testing selection sorting
	ft_printf_fd("[", 1);
	for (int i = 0; i < data.size; i++)
		ft_printf_fd("%d, ", 1, data.values[i]);
	ft_printf_fd("]", 1);
	selection_sort(&data);
	ft_printf_fd("-------------------------\n", 1);
	ft_printf_fd("[", 1);
	for (int i = 0; i < data.size; i++)
		ft_printf_fd("%d, ", 1, data.values[i]);
	ft_printf_fd("]", 1);
	
	print_stack("Stack A", &data);
	printf("\n");
	print_stack("Stack B", &data_b);
	strategy_simple(&data, &data_b);
	printf("\n-----------------------------------\n");
	print_stack("Stack A", &data);
	printf("\n");
	print_stack("Stack B", &data_b);
 } */
