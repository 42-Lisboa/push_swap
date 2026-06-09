/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:41:17 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/09 16:50:21 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	op_rotate(t_array *data);

int	ra(t_array *data, t_count *count_ops)
{
	op_rotate(data);
	ft_printf("ra\n");
	count_ops->ra_count++;
	return (1);
}

int	rb(t_array *data_b, t_count *count_ops)
{
	op_rotate(data_b);
	ft_printf("rb\n");
	count_ops->rb_count++;
	return (1);
}

int	rr(t_array *data, t_array *data_b, t_count *count_ops)
{
	op_rotate(data);
	op_rotate(data_b);
	ft_printf("rr\n");
	count_ops->rr_count++;
	return (1);
}

static void	op_rotate(t_array *data)
{
	int	tmp;

	if (data->size <= 1)
		return ;
	tmp = data->values[data->head];
	data->head = (data->head + 1) % data->capacity;
	data->values[((data->head + data->size -1) % data->capacity)] = tmp;
}
// 47. To find the stack last position after increasing the size->head
// 47. And save the previous first value (tmp) as now the last value
/*
void	print_stack(char *name, t_array *s)
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

    data.capacity = 5;
    data.values = malloc(sizeof(int) * data.capacity);
    data.values[0] = 1; data.values[1] = 2;
	data.values[2] = 3; data.values[3] = 4;
    data.head = 0;
    data.size = 4;

    printf("--- ANTES ---\n");
    print_stack("STACK A", &data);

    printf("--- APLICANDO ra ---\n");

    ra(&data);
    print_stack("\nSTACK A", &data);

    free(data.values);
    return (0);
} */
