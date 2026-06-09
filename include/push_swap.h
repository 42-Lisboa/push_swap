/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:54:38 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/09 20:46:32 by jcosta-a         ###   ########.fr       */
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

int		sa(t_array *data, t_ops *count_op);
int		sb(t_array *data_b, t_ops *count_op);
int		ss(t_array *data, t_array *data_b, t_ops *count_op);
int		pa(t_array *data_b, t_array *data, t_ops *count_op);
int		pb(t_array *data, t_array *data_b, t_ops *count_op);
int		ra(t_array *data, t_ops *count_op);
int		rb(t_array *data_b, t_ops *count_op);
int		rr(t_array *data, t_array *data_b, t_ops *count_op);
int		rra(t_array *data, t_ops *count_op);
int		rrb(t_array *data_b, t_ops *count_op);
int		rrr(t_array *data, t_array *data_b, t_ops *count_op);

int		strategy_simple(t_array *data, t_array *data_b, t_ops *count_op);
int		strategy_medium(t_array *data, t_array *data_b, t_ops *count_op);
int		strategy_complex(t_array *data, t_array *data_b, t_ops *count_op);
int		strategy_adaptive(t_array *data, t_array *data_b, t_ops *count_op);

void	display_bench(t_flags flags, t_array *data, t_ops *count_op, float dis);

#endif