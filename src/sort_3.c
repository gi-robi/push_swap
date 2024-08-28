/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:38:08 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 14:56:37 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5(t_data *db)
{
	int	smallest;
	int	second_smallest;

	smallest = find_smallest(db->sa, db->top_a);
	while (smallest < 4)
	{
		rotate_a(db);
		smallest++;
	}
	push_b(db);
	second_smallest = find_smallest(db->sa, db->top_a);
	while (second_smallest < 3)
	{
		rotate_a(db);
		second_smallest++;
	}
	push_b(db);
	sort_3(db);
	push_a(db);
	push_a(db);
}

void	sort_4(t_data *db)
{
	if (db->sa[1] < db->sa[0] && db->sa[1] < db->sa[2] && db->sa[1] < db->sa[3])
		swap_a(db);
	if (!are_not_sorted(db))
		return ;
	if (db->sa[2] < db->sa[0] && db->sa[2] < db->sa[1] && db->sa[2] < db->sa[3])
	{
		rotate_a(db);
			if (!are_not_sorted(db))
				return ;
		rotate_a(db);
		if (!are_not_sorted(db))
			return ;
	}
	if (db->sa[3] < db->sa[0] && db->sa[3] < db->sa[1] && db->sa[3] < db->sa[2])
		rotate_r_a(db);
	if (!are_not_sorted(db))
		return ; 
	push_b(db);
	sort_3(db);
	push_b(db);
}

void	sort_3(t_data *db)
{
	if (db->sa[1] > db->sa[2] && db->sa[2] > db->sa[0])
	{
		swap_a(db);
		rotate_a(db);
	}
	else if ((db->sa[0] > db->sa[1] && db->sa[0] > db->sa[2]) && db->sa[2] > db->sa[1])
		rotate_a(db);
	else if ((db->sa[0] > db->sa[1] && db->sa[0] > db->sa[2]) && db->sa[2] < db->sa[1])
	{
		swap_a(db);
		rotate_r_a(db);
	}
	else if (db->sa[1] > db->sa[2] && db->sa[2] < db->sa[0])
		rotate_r_a(db);
	else if ((db->sa[2] > db->sa[0] && db->sa[2] > db->sa[1]) && db->sa[0] > db->sa[1])
		swap_a(db);
}
