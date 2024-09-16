/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:06:19 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 16:06:21 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_adjustments(t_data *db)
{
	t_node	*smallest;

	smallest = get_smallest(db->head_a);
	if (smallest->is_below_middle)
		while (db->head_a != smallest)
			rotate_a(&db->head_a, 1);
	else
		while (db->head_a != smallest)
			rotate_r_a(&db->head_a, 1);
}

void	continue_rotation(t_node **head, t_node *cheapest, char stack)
{
	while (*head != cheapest)
	{
		if (stack == 'a')
		{
			if (cheapest->is_below_middle)
				rotate_a(head, 1);
			else
				rotate_r_a(head, 1);
		}
		if (stack == 'b')
		{
			if (cheapest->is_below_middle)
				rotate_b(head, 1);
			else
				rotate_r_b(head, 1);
		}
	}
}

t_node	*get_cheapest_node(t_node *head)
{
	t_node	*current_node;

	current_node = head;
	while (current_node)
	{
		if (current_node->is_cheapest)
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

void	make_move(t_node **head_a, t_node **head_b, t_data *db)
{
	t_node	*cheapest;

	cheapest = get_cheapest_node(*head_b);
	if (cheapest->is_below_middle && cheapest->target_node->is_below_middle)
	{
		while (*head_a != cheapest->target_node && *head_b != cheapest)
			rotate_both(head_a, head_b);
		get_place_in_list(db->head_a);
		get_place_in_list(db->head_b);
	}
	else if (!(cheapest->is_below_middle)
		&& !(cheapest->target_node->is_below_middle))
	{
		while (*head_a != cheapest->target_node && *head_b != cheapest)
			rotate_r_both(head_a, head_b);
		get_place_in_list(db->head_a);
		get_place_in_list(db->head_b);
	}
	if (*head_b != cheapest)
		continue_rotation(head_b, cheapest, 'b');
	if (*head_a != cheapest->target_node)
		continue_rotation(head_a, cheapest->target_node, 'a');
	push_a(db);
}

void	sort_all(t_data *db)
{
	int	len;

	len = len_of_list(db->head_a);
	while (len > 3)
	{
		push_b(db);
		len--;
	}
	sort_3(&db->head_a, db);
	while (db->head_b != NULL)
	{
		get_values(db);
		make_move(&db->head_a, &db->head_b, db);
	}
	get_place_in_list(db->head_a);
	final_adjustments(db);
}
