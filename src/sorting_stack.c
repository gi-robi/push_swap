/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:39:58 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 16:07:03 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_stack(t_data *db)
{
	int	len;

	len = len_of_list(db->head_a);
	if (len == 2)
		swap_a(&db->head_a, 1);
	if (len == 3)
		sort_3(&db->head_a, db);
	else
		sort_all(db);
}
