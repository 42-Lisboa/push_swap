/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/26 22:01:27 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int pa(t_array *data, t_array *data_b)
{
	int tmp;
	if (data_b->size == 0)
		return (0);

	data->size++;
	data->head = (data->head - 1 + data->size) % data->size;
	data->values[data->head] = data_b->values[data_b->head];
	data_b->size--;
	data_b->head = (data_b->head + 1) % data_b->size;	// dentro da manipulacao do head (linhas 22 e 25)
														// precisamos trocar size pelo capacity (ver foto)

	ft_printf("pa");
}

int pb(t_array *data, t_array *data_b)
{
	if (data->size == 0)
		return (0);
	ft_printf("pb");	
}

int main(void)
{
	
}
