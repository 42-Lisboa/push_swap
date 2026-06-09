/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:54:38 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/09 17:33:03 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# include "../libft/libft.h"
# include "utils.h"

int		sa(t_array *data, t_count *count_ops);
int		sb(t_array *data_b, t_count *count_ops);
int		ss(t_array *data, t_array *data_b, t_count *count_ops);
int		pa(t_array *data_b, t_array *data, t_count *count_ops);
int		pb(t_array *data, t_array *data_b, t_count *count_ops);
int		ra(t_array *data, t_count *count_ops);
int		rb(t_array *data_b, t_count *count_ops);
int		rr(t_array *data, t_array *data_b, t_count *count_ops);
int		rra(t_array *data, t_count *count_ops);
int		rrb(t_array *data_b, t_count *count_ops);
int		rrr(t_array *data, t_array *data_b, t_count *count_ops);

int		strategy_simple(t_array *data, t_array *data_b, t_count *count_ops);
int		strategy_medium(t_array *data, t_array *data_b, t_count *count_ops);
int		strategy_complex(t_array *data, t_array *data_b, t_count *count_ops);
int		strategy_adaptive(t_array *data, t_array *data_b, t_count *count_ops);

void	display_bench(t_flags flags, t_array *data, t_count *count_ops, float disorder);

#endif