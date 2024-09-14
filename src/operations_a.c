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
#include <stdio.h>

void	push_a(t_data *db)
{
	t_node	*new_node;

	if (db->head_b == NULL)
		return ;
	new_node = db->head_b;
	db->head_b = db->head_b->next;
	if (db->head_b != NULL)
		db->head_b->prev = NULL;
	new_node->prev = NULL;
	if (db->head_a == NULL)
	{
		db->head_a = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = db->head_a;
		new_node->next->prev = new_node;
		db->head_a = new_node;
	}
	write(1, "pa\n", 3);
}

void	rotate_r_a(t_node **head, int print)
{
	t_node	*new_node;
	int	len;

	len = len_of_list(*head);
	if (head == NULL || *head == NULL || len <= 1)
		return ;
	new_node = get_last_node(*head);
	new_node->prev->next = NULL;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	new_node->next->prev = new_node;
	if (print)
		write(1, "rra\n", 4);
}

void	rotate_a(t_node **head, int print)
{
	t_node	*new_node;
	int	len;
	
	len = len_of_list(*head);
	if (head == NULL || *head == NULL || len <= 1)
		return ;
	new_node = get_last_node(*head);
	new_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	new_node->next->prev = new_node;
	new_node->next->next = NULL;
	if (print)
		write(1, "ra\n", 3);
}

void	swap_a(t_node **head, int print)
{
	int	len;

	len = len_of_list(*head);
	if (head == NULL || *head == NULL || len <= 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	if (print)
		write(1, "sa\n", 3);
}
