/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcas1808          #+#    #+#             */
/*   Updated: 2026/05/25 23:24:11 by jpastolfi        ###   ########.fr       */
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
    // O teu is_valid_number agora deve receber o argv em num_start_idx 
    // para saber exatamente a partir de onde deve começar a ler!
    
    */
   
    // Seg fault: argv começa no meio mas conta a partir do iníciol. Solução:
    // t_array *structure = is_valid_number(argc - num_start_idx + 1, &argv[num_start_idx - 1]);
    // Ou seja, argv vai começar a contar no primeiro número
    // t_array *structure = is_valid_number(argc, &argv[num_start_idx]);
    t_array *structure = is_valid_number(argc - num_start_idx + 1, &argv[num_start_idx - 1]);
    has_duplicates(structure);
    dispatcher(flags.strategy, flags.bench, structure);
    return (0);
}
typedef void (*t_sort_fn)(int benchmark_flag, t_array *structure);

void sort_simple(int bench, t_array *structure)
{
    printf("sort_simple");
}
void sort_medium(int bench, t_array *structure)
{
    printf("sort_medium");
}
void sort_complex(int bench, t_array *structure)
{
    printf("sort_complex");
}
void sort_adaptive(int bench, t_array *structure)
{
    printf("sort_adaptive");
}

void dispatcher(int strategy, int bench, t_array *structure)
{
    t_sort_fn fns[4];
    fns[1] = sort_medium;
    fns[0] = sort_simple;
    fns[2] = sort_complex;
    fns[3] = sort_adaptive;
    printf("strategy: %d\n", strategy);
    printf("bench: %d\n", bench);
    for (int i = 0; i < structure->size; i++)
    {
        printf("Numero extraido: %d\n", structure->values[i]);
    }
    fns[strategy](bench, structure);
}