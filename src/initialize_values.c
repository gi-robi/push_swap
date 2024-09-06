/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:36 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/04 12:32:36 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_lenght(char *argv[])
{
	int	lenght;
	int	i;

	lenght = 0;
	i = 0;
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

	i = db->top_a;
	j = 0;
	while (i >= 0)
	{
		db->sa[j] = (int)ft_atoi_ps(argv[i]);
		i--;
		j++;
	}
}

void	initialize_values(t_data *db, char *argv[])
{
	db->lenght = get_stack_lenght(argv);
	printf("lenght: %d\n", db->lenght);
	db->sa = malloc(db->lenght * sizeof(int));
	db->sb = malloc(db->lenght * sizeof(int));
	if (db->sa == NULL || db->sb == NULL)
		return ;
	db->top_a = db->lenght - 1;
	db->top_b = -1;
	fill_stack(db, argv);
}
