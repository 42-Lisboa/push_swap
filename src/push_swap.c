/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcas1808          #+#    #+#             */
/*   Updated: 2026/06/05 17:45:34 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* int	main(int argc, char **argv)
{
	t_flags	flags;
	t_array	*data;
	t_array	*data_b;
	int		start;

	// 1. Validar se há argumentos suficientes (podes manter a tua função)
	// is_valid_argc(argc, argv);
	// 2. Testar o parser de flags e capturar o índice pivô
	start = parse_all_flags(argc, argv, &flags);
	// 3. Imprimir os resultados para verificação no terminal
	printf("--------------------- Teste do Parser de Flags --------------------\n");
	printf("Estratégia (0=simple, 1=medium, 2=complex, 3=adaptive): >>>>> %d\n", flags.strategy);
	printf("Modo Benchmark (0=off, 1=on): %d\n", flags.bench);
	printf("Os números começam no argv[%d]\n", start);
	printf("-------------------------------------------------------------------\n\n");
	is_valid_number(argc, argv, start);
	has_duplicates(data);
	dispatcher(flags, data);
	return (0);
}

void	sort_simple(t_flags flags, t_array *data, t_array *data_b)
{
	printf("sort_simple");
}

void	sort_medium(t_flags flags, t_array *data, t_array *data_b)
{
	printf("sort_medium");
}

void	sort_complex(t_flags flags, t_array *data, t_array *data_b)
{
	printf("sort_complex");
}

void	sort_adaptive(t_flags flags, t_array *data, t_array *data_b)
{
	printf("sort_adaptive");
}

void	dispatcher(t_flags flags, t_array *data)
{
	t_array		*data_b;
	int			*number_b;
	t_sort_fn	fns[4];

	fns[0] = sort_simple;
	fns[1] = sort_medium;
	fns[2] = sort_complex;
	fns[3] = sort_adaptive;
	number_b = malloc(sizeof(int) * data->capacity);
	if (!number_b)
		end(ERR_MALLOC);
	ft_bzero(number_b, sizeof(int) * data->capacity);
	data_b->values = number_b;
	data_b->size = 0;
	data_b->capacity = data->capacity;
	data_b->head = 0;
	fns[flags.strategy](flags, data, data_b);
} */
