/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcas1808 <jcas1808@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:42:55 by jpastolfi         #+#    #+#             */
/*   Updated: 2026/05/24 04:08:52 by jcas1808         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_valid_argc(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	/* if (parse_all_flags(argv) == argc)
		end(ERR_ARG); */ // mandar para o push_swap com os inputs corretos
}
// 17. Validation of the minimum number of argv;
// 19. Validation of the minimum argv when there's a flag;

static void	fill_data(t_array *data, int argc, char **argv, int i);

t_array	*is_valid_number(int argc, char **argv)
{
	int		i;
	t_array	*data;

	i = 1;
	/* if (has_valid_flag(argv) >= 0)	// Nao precisamos mais fazer essa verificacao
		i++; */						// pois parse_flags retorna proximo index depois da ultima flag
	data = malloc(sizeof(t_array));	// basta entregarmos endereco do **argv na posicao i
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
