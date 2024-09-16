/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:58:49 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 16:18:33 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_cheapest(t_node *head)
{
	t_node	*current_node;
	t_node	*cheapest_node;
	int		cheapest_value;

	if (head == NULL)
		return ;
	current_node = head;
	cheapest_value = INT_MAX;
	while (current_node != NULL)
	{
		if (current_node->price < cheapest_value)
		{
			cheapest_value = current_node->price;
			cheapest_node = current_node;
		}
		current_node->is_cheapest = 0;
		current_node = current_node->next;
	}
	cheapest_node->is_cheapest = 1;
}

void	get_price(t_node *head_a, t_node *head_b)
{
	t_node	*curr;
	int		len_a;
	int		len_b;

	curr = head_b;
	len_a = len_of_list(head_a);
	len_b = len_of_list(head_b);
	while (curr != NULL)
	{
		curr->price = curr->index;
		if (!(curr->is_below_middle))
			curr->price = len_b - (curr->index);
		if (curr->target_node->is_below_middle)
			curr->price += curr->target_node->index;
		else
			curr->price += len_a - (curr->target_node->index);
		if ((curr->is_below_middle && !curr->target_node->is_below_middle)
			|| (curr->target_node->is_below_middle && !curr->is_below_middle))
			curr->price += 2;
		curr = curr->next;
	}
}

void	get_place_in_list(t_node *head)
{
	int		i;
	int		middle;
	t_node	*current_node;
	int		len;

	if (!head)
		return ;
	i = 0;
	current_node = head;
	len = len_of_list(head);
	middle = len / 2;
	while (current_node != NULL)
	{
		current_node->index = i;
		if (i + 1 <= middle)
			current_node->is_below_middle = 1;
		else
			current_node->is_below_middle = 0;
		current_node = current_node->next;
		i++;
	}
}

void	get_target_node(t_node *head_a, t_node *head_b)
{
	t_node	*target_node;
	t_node	*curr_a;
	t_node	*curr_b;
	int		target_value;

	curr_b = head_b;
	while (curr_b != NULL)
	{
		target_value = INT_MAX;
		curr_a = head_a;
		while (curr_a != NULL)
		{
			if (curr_a->value > curr_b->value && curr_a->value < target_value)
			{
				target_value = curr_a->value;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (target_value == INT_MAX)
			curr_b->target_node = get_smallest(head_a);
		else
			curr_b->target_node = target_node;
		curr_b = curr_b->next;
	}
}

void	get_values(t_data *db)
{
	get_place_in_list(db->head_a);
	get_place_in_list(db->head_b);
	get_target_node(db->head_a, db->head_b);
	get_price(db->head_a, db->head_b);
	get_cheapest(db->head_b);
}
