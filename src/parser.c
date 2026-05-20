#include "../include/push_swap.h"

void	is_valid_argc(int argc)
{
	if (argc < 2)
		end(ERR_ARG);
}
// 5. Validation of the minimun number of argv;

int	*is_valid_number(int argc, char **argv)
{
	int	i;
	int	*values;

	i = 1;
	values = malloc(sizeof(int) * (argc - 1));
	if (!values)
		end(ERR_MALLOC);
	while (i < argc)
	{
		if (!(ft_isdigit(argv[i][0]) || argv[i][0] == '-' || argv[i][0] == '+'))
		{
			free(values);
			end(ERR_NOT_VALID);
		}
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
		{
			free(values);
			end(ERR_NOT_VALID);
		}
		values[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (values);
}
// 21. Validation of the first character of each argv;
// 26. Validation if inside INT limits;
// 31. In an array of int we save the treated argv to values;
 
void	has_duplicates(int argc, int *values)
{
	int	i;
	int j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (values[i] == values[j])
				end(ERR_HAS_DUPLICATE);
			j++;
		}
		i++;
	}
}
// 46. Loop to stop at the end of int array;
// 49. Loop to check with the neighbor;
// 52. If has duplicate, stops immediately 

