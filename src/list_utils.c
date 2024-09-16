/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:00:30 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 16:18:03 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_smallest(t_node *head)
{
	int		smallest;
	t_node	*smallest_node;
	t_node	*current_node;

	if (head == NULL)
		return (NULL);
	current_node = head;
	smallest = INT_MAX;
	while (current_node != NULL)
	{
		if (current_node->value < smallest)
		{
			smallest = current_node->value;
			smallest_node = current_node;
		}
		current_node = current_node->next;
	}
	return (smallest_node);
}

int	len_of_list(t_node *head)
{
	int		len;
	t_node	*current_node;

	if (!head)
		return (0);
	len = 0;
	current_node = head;
	while (current_node != NULL)
	{
		len++;
		current_node = current_node->next;
	}
	return (len);
}

t_node	*get_last_node(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
