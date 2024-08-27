/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:36 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 14:58:39 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_lenght(char *argv[])
{
	int	lenght;

	lenght = 0;
	while (argv[lenght])
		lenght++;
	return (lenght);
}

void	fill_stack(int *sa, char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		db->sa[i] = (int)ft_atoi_ps(argv[i]);
		i++;
	}
}

void	initialize_values(t_db *db, char *argv[])
{
	db->lenght = get_stack_lenght(argv);
	db->sa = malloc(db->lenght * sizeof(int));
	db->sb = malloc(db->lenght * sizeof(int));
	//add some error check;
	fill_stack(db->sa, argv);
	db->top_a = lenght - 1;
	db->top_b = -1;
}
