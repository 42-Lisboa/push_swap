/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/29 17:29:07 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_smallest_idx(t_array *data);

void	strategy_simple(t_array *data, t_array *data_b)
{
	int i;
	int	j;

	i = find_smallest_idx(data);
	printf("index i: %d\n", i);
	j = 0;
	if (i <= data->size / 2)
	{
		printf("Entrei no if com index i: %d\n", i);
		while (j <= i)
		{
			printf("Entrei no while com index j: %d\n", j);
			pb(data, data_b);
			j++;
		}
	}
	else
	{
		while (j )
	}
}

void	selection_sort_adapted(t_array *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size - 1)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->values[i] > data->values[j])
				ft_swap(&data->values[i], &data->values[j]);
			j++;
		}
		i++;
	}
}
int	find_smallest_idx(t_array *data)
{
	int	i;
	int	j;

	i = data->head;
	j = i + 1;
		while (j < data->head + data->size)
		{
			if (data->values[i] <= data->values[j])
				j++;
			else
				i = j;
		}
	return (i);
}

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
	
	/* 
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
	ft_printf_fd("]", 1); */
	
	// Testing pb - Strategy Simple
	ft_printf("small@index #%d\n", find_smallest_idx(data.values, data.size));
	print_stack("Stack A", &data);
	printf("\n");
	print_stack("Stack B", &data_b);
	strategy_simple(&data, &data_b);
	printf("\n-----------------------------------\n");
	print_stack("Stack A", &data);
	printf("\n");
	print_stack("Stack B", &data_b);
}

/* 🚧🚧🚧🚧🚧🚧🚧----WIP----🚧🚧🚧🚧🚧🚧🚧 */

