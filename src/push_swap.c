/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcas1808          #+#    #+#             */
/*   Updated: 2026/05/22 17:10:10 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	is_valid_argc(argc, argv);
	t_array *numeros = is_valid_number(argc, argv);
	has_duplicates(argc, numeros);
	has_valid_flag(argv);
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d\n", numeros->values[i]);
	}
}