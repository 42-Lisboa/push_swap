/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:42:55 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/05/21 15:28:42 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_valid_argc(int argc, char **argv)
{
	if (argc < 2)
		end(ERR_ARG);
	if (has_valid_flag(argv) >= 0 && argc < 3)
		end(ERR_ARG);
}
// 17. Validation of the minimun number of argv;
// 19. Validation of the minimum argv when there's a flag

t_array	*is_valid_number(int argc, char **argv)
{
	int	i;
	int j;
	t_array	*data;

	i = 1;
	j = 0;
	if (has_valid_flag(argv) >= 0)
		i++;
	data = malloc(sizeof(t_array));
	if (!data)
		return (NULL);
	data->values = malloc(sizeof(data->values) * (argc - i));
	if (!data->values)
	{
		free(data);
		end(ERR_MALLOC);
	}
	while (i < argc)
	{
		if (!(ft_isdigit(argv[i][0]) || argv[i][0] == '-' || argv[i][0] == '+'))
		{
			free(data->values);
			free(data);
			end(ERR_NOT_VALID);
		}
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
		{
			free(data->values);
			free(data);
			end(ERR_NOT_VALID);
		}
		data->values[j] = ft_atoi(argv[i]);
		i++;
		j++;
		data->size = j;
	}
	return (data);
}
// 35. argc - i: we remove from the count - program and the flag
// 40. Validation of the first character of each argv;
// 45. Validation if inside INT limits;
// 50. In an array of int we save the treated argv to values;
 
void	has_duplicates(int argc, t_array *data)
{
	int	i;
	int j;

	i = 0;
	while (i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->values[i] == data->values[j])
				end(ERR_HAS_DUPLICATE);
			j++;
		}
		i++;
	}
}
// 46. Loop to stop at the end of int array;
// 49. Loop to check with the neighbor;
// 52. If has duplicate, stops immediately 

int has_valid_flag(char **argv)
{
	char *flags[5] = {"simple", "medium", "complex", "adaptive", NULL};
	int i = 0;

	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		while (flags[i])
		{
			if (ft_strncmp(&argv[1][2], flags[i], ft_strlen(&argv[1][2])) == 0)
				return (i);
			i++;
		}
		end(ERR_INVALID_FLAG);
	}
	return (-1);
}

