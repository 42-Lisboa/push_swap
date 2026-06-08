/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcas1808          #+#    #+#             */
/*   Updated: 2026/06/08 15:52:31 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_array	*data;
	t_array	*data_b;
	int		start;

	// 1. Validar se há argumentos suficientes (podes manter a tua função)
	is_valid_argc(argc, argv);
	
	// 2. Testar o parser de flags e capturar o índice do primeiro número
	start = parse_all_flags(argc, argv, &flags);
	if (start == argc)
		end(ERR_ARG);
	
	// 3. Imprimir os resultados para verificação no terminal
	data = validate_number(argc, argv, start);
	has_duplicates(data);
	ft_printf("--------------------- Teste do Parser de Flags --------------------\n");
	ft_printf("Estratégia (0=simple, 1=medium, 2=complex, 3=adaptive): >>>>> %d\n", flags.strategy);
	ft_printf("Modo Benchmark (0=off, 1=on): %d\n", flags.bench);
	ft_printf("Os números começam no argv[%d]\n", start);
	ft_printf("-------------------------------------------------------------------\n\n");
	ft_printf("Número de operações: %d\n", dispatcher(flags, data));
	return (0);
}
int	dispatcher(t_flags flags, t_array *data)
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
	ft_bzero(number_b, sizeof(int) * data->capacity);
	data_b->values = number_b;
	data_b->size = 0;
	data_b->capacity = data->capacity;
	data_b->head = 0;
	data->head = 0;
	fns[0] = strategy_simple;
	fns[1] = strategy_medium;
	fns[2] = strategy_complex;
	fns[3] = strategy_adaptive;
	return (fns[flags.strategy](data, data_b));
}
