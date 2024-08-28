/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:56 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 14:59:05 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_data *db)
{
	if (db->top_b < 0)
		return ;
	db->top_a++;
	db->sa[db->top_a] = db->sb[db->top_b];
	db->top_b--;
	write(1, "pa\n", 3);
}

void	rotate_r_a(t_data *db)
{
	int	temp;
	int	i;

	if (db->top_a <= 0)
		return ;
	temp = db->sa[0];
	i = 0;
	while (i < db->top_a)
	{
		db->sa[i] = db->sa[i + 1];
		i++;
	}
	db->sa[db->top_a] = temp;
	write(1, "rra\n", 4);
}

void	rotate_a(t_data *db)
{
	int	temp;
	int	i;

	if (db->top_a <= 0)
		return ;
	i = db->top_a;
	temp = db->sa[db->top_a];
	while (i > 0)
	{
		db->sa[i] = db->sa[i - 1];
		i--;
	}
	db->sa[i] = temp;
	write (1, "ra\n", 3);
}

void	swap_a(t_data *db)
{
	int	temp;

	if (db->top_a < 1)
		return ;
	temp = db->sa[db->top_a];
	db->sa[db->top_a] = db->sa[db->top_a - 1];
	db->sa[db->top_a - 1] = temp;
	write(1, "sa\n", 3);
}
