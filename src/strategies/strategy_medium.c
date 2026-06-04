/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/04 14:58:23 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	*copy_values(int *numbers, int size);
static int	*sort_copy(int *data, int size);
static int	is_in_bucket(int value, int min, int max);
static int	send_to_bucket(t_array *data, t_array *data_b, int min, int max);

void		print_stack(char *name, t_array *s);

int	strategy_medium(t_array *data, t_array *data_b)
{
	int *sorted;
	int fixed_data_size;
	int	bucket_size;
	int	bucket_start;
	int	bucket_end;
	int	counter;

	counter = 0;
	bucket_start = 0;
	bucket_size = ft_sqrt(data->size);
	bucket_end = bucket_size - 1;
	sorted = sort_copy(copy_values(data->values, data->size), data->size);
	fixed_data_size = data->size;
	while (bucket_start < fixed_data_size)
	{
		counter += send_to_bucket(data, data_b, sorted[bucket_start], sorted[bucket_end]);
		ft_printf("DATA SIZE = %d\n", data->size);
		counter += strategy_simple(data_b, data);
		print_stack("STACK B: ", data_b);
		bucket_start = bucket_end + 1;
		bucket_end = bucket_start + bucket_size - 1;
		if (bucket_end > data->size - 1)
			bucket_end = bucket_start;
	}
	free(sorted);
	return (counter);
}

static int	*copy_values(int *numbers, int size)
{
	int *copied_stack;
	int i;
	
	copied_stack = malloc(sizeof(int) * size);
	if (!copied_stack)
		end(ERR_MALLOC);
	i = 0;
	while (i < size)
	{
		copied_stack[i] = numbers[i];
		i++;
	}
	return (copied_stack);
}

static int *sort_copy(int *numbers, int size)
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

static int is_in_bucket(int value, int min, int max)
{
	return (min <= value && value <= max);
}

static int	send_to_bucket(t_array *data, t_array *data_b, int min, int max)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (is_in_bucket(data->values[data->head], min, max))
			pb(data, data_b);
		else
			ra(data);
		i++;
	}
	return (i - 1);
}
void	print_stack(char *name, t_array *s)
{
	ft_printf("%s: ", name);
    for (int i = 0; i < s->size; i++)
    {
        int idx = (s->head + i) % s->capacity;
        ft_printf("%d ", s->values[idx]);
    }
    ft_printf("\n");
}

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
