/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcas1808          #+#    #+#             */
/*   Updated: 2026/06/09 17:34:58 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_array	*data;
	t_count	*count_ops;
	int		start;
	float	disorder;

	is_valid_argc(argc, argv);
	start = parse_all_flags(argc, argv, &flags);
	data = validate_number(argc, argv, start);
	has_duplicates(data);
	count_ops = malloc(sizeof(t_count));
	if (!count_ops)
		end(ERR_MALLOC);
	count_ops_to_zero(count_ops);
	disorder = compute_disorder(data);
	count_ops->total_count = dispatcher(flags, data, count_ops);
	if (flags.bench)
		display_bench(flags, data, count_ops, disorder);
	return (0);
}
// 00. Validar se há argumentos suficientes
// 00. Testar o parser de flags e capturar o índice do primeiro número
// 00. Imprimir os resultados para verificação no terminal

int	dispatcher(t_flags flags, t_array *data, t_count *count_ops)
{
	t_array		*data_b;
	int			*number_b;
	t_sort_fn	fns[4];

	data_b = malloc(sizeof(t_array));
	if (!data_b)
		end(ERR_MALLOC);
	number_b = malloc(sizeof(int) * data->capacity);
	if (!number_b)
		end(ERR_MALLOC);
	data_b->values = number_b;
	data_b->size = 0;
	data_b->capacity = data->capacity;
	data_b->head = 0;
	fns[0] = strategy_simple;
	fns[1] = strategy_medium;
	fns[2] = strategy_complex;
	fns[3] = strategy_adaptive;
	return (fns[flags.strategy](data, data_b, count_ops));
}

void display_bench(t_flags flags, t_array *data, t_count *count_ops, float disorder)
{
	char *flags_titles[4];

	flags_titles[0] = "Simple";
	flags_titles[1] = "Medium";
	flags_titles[2] = "Complex";
	flags_titles[3] = "Adaptive";
	ft_printf("[bench] disorder: %d%%\n", (int)(disorder * 100));
	ft_printf("[bench] total_ops: %d\n", count_ops->total_count);
	ft_printf("[bench] sa: %d  ", count_ops->sa_count);
	ft_printf("[bench] sb: %d  ", count_ops->sb_count);
	ft_printf("[bench] ss: %d  ", count_ops->ss_count);
	ft_printf("[bench] pa: %d  ", count_ops->pa_count);
	ft_printf("[bench] pb: %d\n", count_ops->pb_count);
	ft_printf("[bench] ra: %d  ", count_ops->ra_count);
	ft_printf("[bench] rb: %d  ", count_ops->rb_count);
	ft_printf("[bench] rr: %d  ", count_ops->rr_count);
	ft_printf("[bench] rra: %d  ", count_ops->rra_count);
	ft_printf("[bench] rrb: %d  ", count_ops->rrb_count);
	ft_printf("[bench] rrr: %d\n", count_ops->rrr_count);
}

void count_ops_to_zero(t_count *count_ops)
{
	count_ops->sa_count = 0;
	count_ops->sb_count = 0;
	count_ops->ss_count = 0;
	count_ops->pa_count = 0;
	count_ops->pb_count = 0;
	count_ops->ra_count = 0;
	count_ops->rb_count = 0;
	count_ops->rr_count = 0;
	count_ops->rra_count = 0;
	count_ops->rrb_count = 0;
	count_ops->rrr_count = 0;
	count_ops->total_count = 0;
}
