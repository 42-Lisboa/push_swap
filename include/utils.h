#ifndef UTILS_H
# define UTILS_H

# define ERR_ARG 1
# define ERR_NOT_VALID 2
# define ERR_HAS_DUPLICATE 3
# define ERR_MALLOC 4
# define ERR_INVALID_FLAG 5

typedef struct  s_array
{
    int         *values;
    int         size;
    int         head;
    int         capacity;
}   t_array;

typedef struct	s_flags
{
	int			strategy;
    int			bench;
}	t_flags;

typedef void (*t_sort_fn)(t_flags flags, t_array *data, t_array *data_b);

void	is_valid_argc(int argc, char **argv);
t_array	*is_valid_number(int argc, char **argv, int start);
void	has_duplicates(t_array *data);
int		parse_all_flags(int argc, char **argv, t_flags *flag);
int		get_strategy_idx(char *argv);
void	end(int	error);
void    dispatcher(t_flags flags, t_array *structure);
int     movements_to_smallest(t_array *data);
int     swap_small_stack(t_array *data, t_array *data_b);

#endif
