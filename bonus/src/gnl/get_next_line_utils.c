/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:49:01 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 15:49:04 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	fill_new_list(t_list *tmp, t_list *new_list)
{
	t_list		*new_node;
	int			j;
	int			i;

	new_node = new_list;
	i = 0;
	while (tmp->content[i] != '\n')
		i++;
	i++;
	while (tmp)
	{
		j = 0;
		while (tmp->content[i] != '\0')
			new_node->content[j++] = tmp->content[i++];
		new_node->content[j] = '\0';
		tmp = tmp->next;
		if (tmp != NULL && new_node->content[0] != '\0')
		{
			new_node->next = malloc(sizeof(t_list));
			new_node = new_node->next;
			if (new_node == NULL)
				return ;
		}
		i = 0;
	}
}

void	reset_list(t_list **list)
{
	int		i;
	t_list	*tmp;
	t_list	*new_list;

	new_list = add_new_node(list, 1);
	tmp = *list;
	while (tmp && new_list)
	{
		i = 0;
		while (tmp->content[i] != '\0')
		{
			if (tmp->content[i] == '\n')
				break ;
			i++;
		}
		if (tmp->content[i] == '\n')
		{
			fill_new_list(tmp, new_list);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *list;
	*list = new_list;
	free_all(&tmp);
}

void	remove_last_node(t_list **list)
{
	t_list	*tmp;
	t_list	*new_last;

	if (!*list)
		return ;
	tmp = *list;
	if (tmp->next == NULL)
	{
		free(tmp);
		*list = NULL;
		return ;
	}
	while (tmp->next)
	{
		new_last = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	new_last->next = NULL;
}

void	fill_line(t_list *list, char *line, int line_len)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = list;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] != '\0' && j < line_len
			&& tmp->content[i] != '\n')
		{
			line[j] = tmp->content[i];
			j++;
			i++;
		}
		if (tmp->content[i] == '\n')
		{
			line[j] = '\n';
			j++;
			break ;
		}
		tmp = tmp->next;
	}
	line[j] = '\0';
}

void	free_all(t_list **list)
{
	t_list	*current;
	t_list	*tmp;

	if (!list || !*list)
		return ;
	current = *list;
	while (current->next)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free (current);
	*list = NULL;
}
