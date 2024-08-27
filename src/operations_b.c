/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:01:15 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 15:01:52 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_data *db)
{
	if (db->top_a < 0)
		return ;
	db->top_b++;
	db->sb[db->top_b] = db->sa[db->top_a];
	db->top_a--;
	write(1, "pb\n", 3);
}
