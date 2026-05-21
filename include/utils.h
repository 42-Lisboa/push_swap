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
    int         *head;
}               t_array;

void	is_valid_argc(int argc, char **argv);
t_array	*is_valid_number(int argc, char **argv);
void	has_duplicates(int argc, t_array *data);
int     has_valid_flag(char **argv);
void	end(int	error);

#endif