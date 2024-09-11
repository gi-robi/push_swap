#include "../includes/push_swap.h"

void	make_move(t_data *db)
{
	int	cheap_index;
	int	target;
	int	cheap;

	
	cheap_index = find_cheap_index(db);
	cheap = db->sb[cheap_index];
	target = db->sa[db->target[cheap_index]];
	if (cheap_index > (db->top_b + 1) / 2 && db->target[cheap_index] > (db->top_a + 1) / 2)
		rotate_both(db);
	else if (cheap_index > (db->top_b + 1) / 2 && db->target[cheap_index] > (db->top_a + 1) / 2)
		rotate_r_both(db);
	while (db->sb[0] != cheap)
		
	if (db->sa[0] != target)
		continue_rotation(db, cheap, a);
	

int	find_cheap_index(t_data *db)
{
	int	i;
	int	cheapest_index;
	int	cheapest_value;

	i = 1;
	cheapest_index = 0;
	cheapest_value = db->price[0];
	while (i <= db->top_b)
	{
		if (db->price[i] < cheapest_value)
		{
			cheapest_value = db->price[i];
			cheapest_index = i;
		}
		i++;
	}
	return (cheapest_index);
}
	
void	set_price(t_data *db)
{
	int	price_b;
	int	price_a;
	int	i;

	i = 0;
	while (i <= db->top_b)
	{
		price_b = i;
		price_a = db->target[i];
		if (i > (db->top_b + 1) / 2)
			price_b = db->top_b - i;
		if (db->target[i] > (db->top_a + 1) / 2)
			price_a = db->top_a - db->target[i];
		db->price[i] = price_b + price_a;
		if ((i > (db->top_b + 1) / 2 && db->target[i] <= (db->top_a + 1) / 2)
		|| (i <= (db->top_b + 1) / 2 && db->target[i] > (db->top_a + 1) / 2))
			db->price[i] += 2;
		i++;
	}
}

void	set_target(t_data *db)
{
	int	i;
	int	j;
	int	best_value;
	int	best_index;

	i = 0;
	while (i <= db->top_b)
	{
		j = 0;
		best_index = -1;
		best_value = INT_MAX;
		while (j <= db->top_a)
		{
			if (db->sa[j] > db->sb[i] && db->sa[j] < best_value)
			{
				best_value = db->sa[j];
				best_index = j;
			}
			j++;
		}
		if (best_index == -1)
			best_index = find_smallest(db->sa, db->top_a);
		db->target[i] = best_index;
		i++;
	}
}

void	allocate_target_and_price(t_data *db)
{
	db->target = malloc((db->top_b + 1) * sizeof(int));
	if (db->target == NULL)
		free_all_and_exit(db);
	db->price = malloc((db->top_b + 1) * sizeof(int));
	if (db->price == NULL)
		free_all_and_exit(db);
}

void	set_values(t_data *db)
{
	allocate_target_and_price(db);
	set_target(db);
	set_price(db);
	
}	

void	sort_turk(t_data db)
{
	while (db->top_a > 2)
		push_b(db);
	sort_3(db);
	while (db->top_b > 0)
	{
		set_values(db);
		make_move(db);
		free(db->target);
		free(db->price);
	}
	final_adjustements_a(db);
}
