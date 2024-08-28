/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:39:58 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 15:00:02 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_stack(t_data *db)
{
	if (db->lenght == 2)
		swap_a(db);
	if (db->lenght == 3)
		sort_3(db);
	if (db->lenght == 4)
		sort_4(db);
	if (db->lenght == 5)
		sort_5(db);
}
