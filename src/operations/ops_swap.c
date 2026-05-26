/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:06:43 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/26 20:30:08 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sa(t_array *data)
{
	int	tmp;

	if (data->size <= 1)
		return (0);
	tmp = data->values[data->head % data->size]; // aqui tambem precisamos utilizar capacity
	data->values[data->head % data->size]
		= data->values[(data->head + 1) % data->size];
	data->values[(data->head + 1) % data->size] = tmp;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_array *data_b)
{
	int	tmp;

	if (data_b->size <= 1)
		return (0);
	tmp = data_b->values[data_b->head % data_b->size];
	data_b->values[data_b->head % data_b->size]
		= data_b->values[(data_b->head + 1) % data_b->size];
	data_b->values[(data_b->head + 1) % data_b->size] = tmp;
	ft_printf("sb\n");
	return (1);
}

int	ss(t_array *data, t_array *data_b)
{
	int	tmp;

	if (data->size <= 1 && data_b->size <= 1)
		return (0);
	if (data->size > 1)
	{
		tmp = data->values[data->head % data->size];
		data->values[data->head % data->size]
			= data->values[(data->head + 1) % data->size];
		data->values[(data->head + 1) % data->size] = tmp;
	}
	if (data_b->size > 1)
	{
		tmp = data_b->values[data_b->head % data_b->size];
		data_b->values[data_b->head % data_b->size]
			= data_b->values[(data_b->head + 1) % data_b->size];
		data_b->values[(data_b->head + 1) % data_b->size] = tmp;
	}
	ft_printf("ss\n");
	return (1);
}
/* 
int main(void)
{
	printf("------------- sa --------------\n");
	t_array data;
	data.values = malloc(sizeof(int) * 4);
	data.values[0] = 1;
	data.values[1] = 2;
	data.values[2] = 3;
	data.values[3] = 4;
	data.head = 3;
	data.tail = 3;
	data.size = 4;
	sa(&data);
	for (int i = 0; i < data.size; i++)
	{
		printf("%d\n", data.values[i]);
	}
	printf("--------------------------------\n");

	printf("------------- sb --------------\n");
	t_array data_b;
	data_b.values = malloc(sizeof(int) * 4);
	data_b.values[0] = 5;
	data_b.values[1] = 6;
	data_b.values[2] = 7;
	data_b.values[3] = 8;
	data_b.head = 3;
	data_b.tail = 3;
	data_b.size = 4;
	sb(&data_b);
	for (int i = 0; i < data_b.size; i++)
	{
		printf("%d\n", data_b.values[i]);
	}
	printf("--------------------------------\n");
	printf("------------- ss --------------\n");
	ss(&data, &data_b);
	for (int i = 0; i < data.size; i++)
	{
		printf("%d\n", data.values[i]);
	}
	for (int i = 0; i < data.size; i++)
	{
		printf("%d\n", data_b.values[i]);
	}
	printf("--------------------------------\n");
	return (0);
} */
