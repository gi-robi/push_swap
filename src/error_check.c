/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:11:40 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 15:11:34 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_not_digit(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_over_limits(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi_ps(argv[i]) > INT_MAX || ft_atoi_ps(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	is_double_number(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi_ps(argv[i]) == ft_atoi_ps(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check(char *argv[])
{
	if (is_not_digit(argv))
		return (1);
	if (is_over_limits(argv))
		return (1);
	if (is_double_number(argv))
		return (1);
	return (0);
}		
