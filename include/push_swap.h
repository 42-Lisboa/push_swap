/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:54:38 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/03 14:54:39 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h> // remover no final

# include "../libft/libft.h"
# include "utils.h"

int	sa(t_array *data);
int	sb(t_array *data_b);
int	ss(t_array *data, t_array *data_b);
int	pa(t_array *data_b, t_array *data);
int	pb(t_array *data, t_array *data_b);
int	ra(t_array *data);
int	rb(t_array *data_b);
int	rr(t_array *data, t_array *data_b);
int	rra(t_array *data);
int	rrb(t_array *data_b);
int	rrr(t_array *data, t_array *data_b);

#endif