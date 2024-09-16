/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:14:36 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 16:17:20 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_first_node(t_node **head, t_node **end, int num, t_data *db)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		free_all(db);
		write(2, "Allocation failed.\n", 19);
		exit (1);
	}
	new_node->value = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	*head = new_node;
	*end = new_node;
}

void	sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	store_middle(t_data *db)
{
	int		*array;
	int		i;
	t_node	*current_node;
	int		len;

	len = len_of_list(db->head_a);
	array = malloc(len * sizeof(int));
	if (array == NULL)
	{
		free_all(db);
		write(2, "Allocation failed.\n", 19);
		exit (1);
	}
	i = 0;
	current_node = db->head_a;
	while (current_node != NULL)
	{
		array[i] = current_node->value;
		current_node = current_node->next;
		i++;
	}
	sort_array(array, len);
	db->middle = array[len / 2];
	free(array);
}

void	put_node_end(t_node **head, t_node **end, int num, t_data *db)
{
	t_node	*new_node;

	if (*head == NULL)
	{
		put_first_node(head, end, num, db);
		return ;
	}
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_all(db);
		write(2, "Node allocation failed.\n", 24);
		exit (1);
	}
	new_node->value = num;
	new_node->prev = *end;
	new_node->next = NULL;
	(*end)->next = new_node;
	*end = new_node;
}

void	initialize_values(t_data *db)
{
	int	i;
	int	num;

	i = 0;
	db->head_a = NULL;
	db->head_b = NULL;
	db->end_a = NULL;
	while (db->tab[i])
	{
		num = (int)ft_atoi_ps(db->tab[i]);
		put_node_end(&db->head_a, &db->end_a, num, db);
		i++;
	}
	free_tab(db);
	store_middle(db);
}
