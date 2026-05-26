/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:10:09 by jcas1808          #+#    #+#             */
/*   Updated: 2026/05/26 15:11:48 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_flags flags;
    t_array *data_b;
    int     start;

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

    /* // 4. Integração futura com os números (comentada por agora)
    // O teu is_valid_number agora deve receber o argv em start 
    // para saber exatamente a partir de onde deve começar a ler!
    
    */
   
    // Seg fault: argv começa no meio mas conta a partir do iníciol. Solução:
    // t_array *structure = is_valid_number(argc - start + 1, &argv[start - 1]);
    // Ou seja, argv vai começar a contar no primeiro número
    t_array *data = is_valid_number(argc, argv, start);
    has_duplicates(data);
    dispatcher(flags, data, data_b);
    return (0);
}

void sort_simple(t_flags flags, t_array *data, t_array *data_b)
{
    printf("sort_simple");
}
void sort_medium(t_flags flags, t_array *data, t_array *data_b)
{
    printf("sort_medium");
}
void sort_complex(t_flags flags, t_array *data, t_array *data_b)
{
    printf("sort_complex");
}
void sort_adaptive(t_flags flags, t_array *data, t_array *data_b)
{
    printf("sort_adaptive");
}

void dispatcher(t_flags flags, t_array *data, t_array *data_b)
{
    t_sort_fn fns[4];
    fns[0] = sort_simple;
    fns[1] = sort_medium;
    fns[2] = sort_complex;
    fns[3] = sort_adaptive;
/*     printf("strategy: %d\n", strategy);
    printf("bench: %d\n", bench);
    for (int i = 0; i < data->size; i++)
    {
        printf("Numero extraido: %d\n", data->values[i]);
    } */
    fns[flags.strategy](flags, data, data_b);
}
