/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/04 13:03:28 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

void	print_stack(char *name, t_array *s);
int		*copy_values(int *numbers, int size);
int		*sort_copy(int *data, int size);
int		is_inside_chunk(int value, int min, int max);
int		find_position_inside_chunk(t_array *data, int min, int max);

int	strategy_medium(t_array *data, t_array *data_b)
{
	int *ordered_stack_a;
	int index;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	index = 0;
	chunk_start = 0;
	chunk_size = ft_sqrt(data->size);
	chunk_end = chunk_size - 1;
	ordered_stack_a = sort_copy(copy_values(data->values, data->size), data->size);
	while (chunk_start < data->size)
	{
		find_position_inside_chunk(data, ordered_stack_a[chunk_start], ordered_stack_a[chunk_end]);
		chunk_start = chunk_end + 1;
		chunk_end = chunk_start + chunk_size - 1;
		if (chunk_end > data->size - 1)
			chunk_end = data->size - 1;
	}
	free(ordered_stack_a);	
	return (1);
}

int	*copy_values(int *numbers, int size)
{
	int *copied_stack;
	int index;
	
	copied_stack = malloc(sizeof(int) * size);
	if (!copied_stack)
		end(ERR_MALLOC);
	index = 0;
	while (index < size)
	{
		copied_stack[index] = numbers[index];
		index++;
	}
	return (copied_stack);
}

int *sort_copy(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
				ft_swap(&numbers[i], &numbers[j]);
			j++;
		}
		i++;
	}
	return (numbers);
}

int is_inside_chunk(int value, int min, int max)
{
	return (min <= value && value <= max);
}

int find_position_inside_chunk(t_array *data, int min, int max)
{
	int	index;

	index = 0;
	while (index < data->size)
	{
		if (is_inside_chunk(data->values[index], min, max))
			return (index);
		index++;
	}
	return (-1);
}
/* void	print_stack(char *name, t_array *s)
{
	ft_printf("%s: ", name);
    for (int i = 0; i < s->size; i++)
    {
        int idx = (s->head + i) % s->capacity;
        ft_printf("%d ", s->values[idx]);
    }
    ft_printf("\n");
} */

int main(void)
{
	t_array data;
	int	number[] = {2, 8, 1, 4, 9, 332, -2, 0, 58, 22, 32, +69, 21497};
	data.values = number;
	data.size = 13;
	data.capacity = 13;
	data.head = 0;

	t_array data_b;
	int number_b[13] = {0};
	data_b.values = number_b;
	data_b.size = 0;
	data_b.capacity = 13;
	data_b.head = 0;

	strategy_medium(&data, &data_b);
}