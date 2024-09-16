/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:56:25 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 15:56:34 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(t_data *db)
{
	int	i;

	i = 0;
	if (db->is_tab_all)
	{
		while (db->tab[i])
		{
			free(db->tab[i]);
			i++;
		}
		free(db->tab);
		db->is_tab_all = 0;
	}
}

void	free_stack(t_node **head)
{
	t_node	*current_node;

	current_node = *head;
	if (*head == NULL)
		return ;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
		free(current_node->prev);
	}
	free(current_node);
}

void	free_all(t_data *db)
{
	free_tab(db);
	free_stack(&db->head_a);
	free_stack(&db->head_b);
}
