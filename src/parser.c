/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:42:55 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/05/22 18:34:03 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_valid_argc(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	if (has_valid_flag(argv) >= 0 && argc < 3)
		end(ERR_ARG); // mandar para o push_swap.
}
// 17. Validation of the minimun number of argv;
// 19. Validation of the minimum argv when there's a flag;

static void	fill_data(t_array *data, int argc, char **argv, int i);

t_array	*is_valid_number(int argc, char **argv)
{
	int		i;
	t_array	*data;

	i = 1;
	if (has_valid_flag(argv) >= 0)
		i++;
	data = malloc(sizeof(t_array));
	if (!data)
		return (NULL);
	data->values = malloc(sizeof(int) * (argc - i));
	if (!data->values)
	{
		free(data);
		end(ERR_MALLOC);
	}
	fill_data(data, argc, argv, i);
	return (data);
}
// 35. argc - i: we remove from the count - program and the flag

static void	fill_data(t_array *data, int argc, char **argv, int i)
{
	int	j;

	j = 0;
	while (i < argc)
	{
		if ((!(ft_isdigit(argv[i][0])
				|| argv[i][0] == '-' && ft_isdigit(argv[i][1])
				|| argv[i][0] == '+' && ft_isdigit(argv[i][1]))))
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
}
// 56. First character of each argv cannot be different from sign or digit;
// 57. If there is a sign, also 2nd character from argv needs to be digit;
// 63. Validation if inside INT limits;
// 69. In an array of int on a struct we save the treated argv to values;

void	has_duplicates(t_array *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->values[i] == data->values[j])
			{
				free(data->values);
				free(data);
				end(ERR_HAS_DUPLICATE);
			}
			j++;
		}
		i++;
	}
}
// 46. Loop to stop at the end of int array;
// 49. Loop to check with the neighbor;
// 52. If has duplicate, stops immediately 

int	has_valid_flag(char **argv)
{
	char	*flags[5];
	int		i;

	flags[0] = "simple";
	flags[1] = "medium";
	flags[2] = "complex";
	flags[3] = "adaptive";
	flags[4] = NULL;
	i = -1;
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		while (flags[++i])
		{
			if (ft_strlen(&argv[1][2]) != ft_strlen(flags[i]))
				continue ;
			if (ft_strncmp(&argv[1][2], flags[i], ft_strlen(&argv[1][2])) == 0)
				return (i);
		}
		end(ERR_INVALID_FLAG);
	}
	return (-1);
}
