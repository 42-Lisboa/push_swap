/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:54:52 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/10 20:41:31 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define ERR_ARG 1
# define ERR_NOT_VALID 2
# define ERR_HAS_DUPLICATE 3
# define ERR_MALLOC 4
# define ERR_INVALID_FLAG 5

typedef struct s_array
{
	int			*values;
	int			size;
	int			head;
	int			capacity;
}	t_array;

typedef struct s_flags
{
	int	strategy;
	int	bench;
}	t_flags;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_count;
}	t_ops;

typedef int	(*t_sort_fn)(t_array *data, t_array *data_b, t_ops *count_op);

void	is_valid_argc(int argc);
t_array	*validate_number(int argc, char **argv, int start);
void	has_duplicates(t_array *data);
int		parse_all_flags(int argc, char **argv, t_flags *flag);
int		get_strategy_idx(char *argv);
void	end(int error);
int		dispatcher(t_flags flags, t_array *structure, t_ops *count_op);
int		movements_to_smallest(t_array *data);
int		movements_to_greatest(t_array *data_b);
int		movements_next_bucket_val(t_array *src, int min, int max);
int		is_in_bucket(int value, int min, int max);
int		swap_small_stack(t_array *data, t_array *data_b, t_ops *count_op);
int		*copy_values(int *numbers, int size);
int		*sort_copy(int *numbers, int size);
float	compute_disorder(t_array *data);
void	count_op_to_zero(t_ops *count_op);

#endif
