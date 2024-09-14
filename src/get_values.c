#include "../includes/push_swap.h"

void	get_cheapest(t_node *head)
{
	t_node	*current_node;
	t_node	*cheapest_node;
	int	cheapest_value;

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
	t_node	*current_node;
	int	len_a;
	int	len_b;

	current_node = head_b;
	len_a = len_of_list(head_a);
	len_b = len_of_list(head_b);
	while (current_node != NULL)
	{
		current_node->price = current_node->index;
		if (!(current_node->is_below_middle))
			current_node->price = len_b - (current_node->index);
		if (current_node->target_node->is_below_middle)
			current_node->price += current_node->target_node->index;
		else
			current_node->price += len_a - (current_node->target_node->index);
		if ((current_node->is_below_middle && !current_node->target_node->is_below_middle)
			|| (current_node->target_node->is_below_middle
				&& !current_node->is_below_middle))
			current_node->price += 2;
		current_node = current_node->next;
	}
}

t_node	*get_smallest(t_node *head)
{
	int	smallest;
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

void	get_place_in_list(t_node *head)
{
	int	i;
	int	middle;
	t_node	*current_node;
	int	len;

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
	t_node	*current_a;
	t_node	*current_b;
	int	target_value;

	current_b = head_b;
	while (current_b != NULL)
	{
		target_value = INT_MAX;
		current_a = head_a;
		while (current_a != NULL)
		{
			if (current_a->value > current_b->value && current_a->value < target_value)
			{
				target_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (target_value == INT_MAX)
			current_b->target_node = get_smallest(head_a);
		else
			current_b->target_node = target_node;
		current_b = current_b->next;
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
