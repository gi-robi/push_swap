/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:36 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 15:23:05 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_lenght(char *argv[])
{
	int	lenght;
	int	i;

	lenght = 0;
	i = 1;
	while (argv[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

void	fill_stack(t_data *db, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		db->sa[j] = (int)ft_atoi_ps(argv[i]);
		i++;
		j++;
	}
}

void	initialize_values(t_data *db, char *argv[])
{
	db->lenght = get_stack_lenght(argv);
	db->sa = malloc(db->lenght * sizeof(int));
	db->sb = malloc(db->lenght * sizeof(int));
	//add some error check;
	fill_stack(db, argv);
	db->top_a = db->lenght - 1;
	db->top_b = -1;
}
