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
#include <stdio.h>

void	sort_3(t_node **head, t_data *db)
{
	int	max_num;
	t_node	*max_ptr;
	t_node	*current_node;
	
	current_node = *head;
	max_num = INT_MIN;
	while (current_node)   //consider putting this in a function find_max
	{
		if (current_node->value > max_num)
		{
			max_num = current_node->value;
			max_ptr = current_node;
		}
		current_node = current_node->next;
	}
	if (max_ptr == *head)
		rotate_a(&db->head_a, 1);
	else if (max_ptr == (*head)->next)
		rotate_r_a(&db->head_a, 1);
	if ((*head)->value > (*head)->next->value)
		swap_a(&db->head_a, 1);
}
