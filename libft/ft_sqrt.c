/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastolfi <jpastolfi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:40:03 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/03 14:59:42 by jpastolfi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int number)
{
	int	i;

	if (number < 0)
		return (0);
	if (number <= 1)
		return (number);
	i = 1;
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}
