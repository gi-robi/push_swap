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
	t_node	*new_node;

	if (db->head_a == NULL)
		return ;
	new_node = db->head_a;
	db->head_a = db->head_a->next;
	if (db->head_a != NULL)
		db->head_a->prev = NULL;
	new_node->prev = NULL;
	if (db->head_b == NULL)
	{
		db->head_b = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = db->head_b;
		new_node->next->prev = new_node;
		db->head_b = new_node;
	}
	write(1, "pb\n", 3);
}

void    rotate_b(t_node **head, int print)
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
		write (1, "rb\n", 3);
}

void    rotate_r_b(t_node **head, int print)
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
		write(1, "rrb\n", 4);
}

void    swap_b(t_node **head, int print)
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
		write(1, "sb\n", 3);
}
