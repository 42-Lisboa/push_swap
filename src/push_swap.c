/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcas1808          #+#    #+#             */
/*   Updated: 2026/05/24 04:22:48 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_flags flags;
    int     num_start_idx;

    // 1. Validar se há argumentos suficientes (podes manter a tua função)
    // is_valid_argc(argc, argv);

    // 2. Testar o parser de flags e capturar o índice pivô
    num_start_idx = parse_all_flags(argc, argv, &flags);

    // 3. Imprimir os resultados para verificação no terminal
    printf("--------------------- Teste do Parser de Flags --------------------\n");
    printf("Estratégia (0=simple, 1=medium, 2=complex, 3=adaptive): >>>>> %d\n", flags.strategy);
    printf("Modo Benchmark (0=off, 1=on): %d\n", flags.bench);
    printf("Os números começam no argv[%d]\n", num_start_idx);
    printf("-------------------------------------------------------------------\n\n");

    /* // 4. Integração futura com os números (comentada por agora)
    // O teu is_valid_number agora deve receber o arv em num_start_idx 
    // para saber exatamente a partir de onde deve começar a ler!
    
    t_array *numeros = is_valid_number(argc, &argv[i]);
    has_duplicates(numeros);
    
    for (int i = 0; i < numeros->size; i++)
    {
        printf("Numero extraido: %d\n", numeros->values[i]);
    }
    */

    return (0);
}