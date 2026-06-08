/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:54:52 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/06/08 15:51:46 by jpastolfi        ###   ########.fr       */
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

typedef int	(*t_sort_fn)(t_array *data, t_array *data_b);

void	is_valid_argc(int argc, char **argv);
t_array	*validate_number(int argc, char **argv, int start);
void	has_duplicates(t_array *data);
int		parse_all_flags(int argc, char **argv, t_flags *flag);
int		get_strategy_idx(char *argv);
void	end(int error);
int		dispatcher(t_flags flags, t_array *structure);
int		movements_to_smallest(t_array *data);
int		movements_to_greatest(t_array *data_b);
int		movements_next_bucket_val(t_array *src, int min, int max);
int		is_in_bucket(int value, int min, int max);
int		swap_small_stack(t_array *data, t_array *data_b);
int		*copy_values(int *numbers, int size);
int		*sort_copy(int *numbers, int size);

#endif
