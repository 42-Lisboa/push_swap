#ifndef UTILS_H
# define UTILS_H

# define ERR_ARG 1
# define ERR_NOT_VALID 2
# define ERR_HAS_DUPLICATE 3
# define ERR_MALLOC 4

void	is_valid_argc(int argc);
int		*is_valid_number(int argc, char **argv);
void	has_duplicates(int argc, int *values);
void	end(int	error);

#endif