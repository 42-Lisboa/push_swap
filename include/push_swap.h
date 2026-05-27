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

#endif