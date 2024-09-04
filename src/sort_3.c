/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:38:08 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/04 11:55:35 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5(t_data *db)
{
	int	min_index;
	int	min_number;

	min_index = find_smallest(db->sa, db->top_a);
	min_number = db->sa[min_index];
	while (db->sa[4] != min_number)
	{
		if (min_index > 1)
			rotate_a(db);
		else
			rotate_r_a(db);
	}
	push_b(db);
	sort_4(db);
	push_a(db);
}

void	sort_4(t_data *db)
{
	int	min_index;
	int	min_number;

	min_index = find_smallest(db->sa, db->top_a);
	min_number = db->sa[min_index];
	if (min_index == 2)
		swap_a(db);
	while (db->sa[3] != min_number)
		rotate_r_a(db);
	push_b(db);
	sort_3(db);
	push_a(db);
}

void	sort_3(t_data *db)
{
	int	min;
	
	min = find_smallest(db->sa, db->top_a);
	if (min == 2 && db->sa[1] > db->sa[0])
	{
		rotate_r_a(db);
		swap_a(db);
	}
	else if (min == 1 && db->sa[2] > db->sa[0])
		rotate_a(db);
	else if (min == 0 && db->sa[2] > db->sa[1])
	{
		rotate_a(db);
		swap_a(db);
	}
	else if (min == 0 && db->sa[1] > db->sa[2])
		rotate_r_a(db);
	else if (min == 1 && db->sa[0] > db->sa[2])
		swap_a(db);
}
