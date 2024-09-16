/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:11:40 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 15:55:48 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_node *head)
{
	t_node	*current_node;

	if (head == NULL)
		return (1);
	current_node = head;
	while (current_node->next)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

int	is_not_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-')
			j++;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_over_limits(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atoi_ps(tab[i]) > INT_MAX || ft_atoi_ps(tab[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	is_double_number(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi_ps(tab[i]) == ft_atoi_ps(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check(t_data *db, char **tab)
{
	int	error;

	error = 0;
	if (is_not_digit(tab))
		error = 1;
	if (is_over_limits(tab))
		error = 1;
	if (is_double_number(tab))
		error = 1;
	if (error)
	{
		if (db->is_tab_all)
			free_tab(db);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}
