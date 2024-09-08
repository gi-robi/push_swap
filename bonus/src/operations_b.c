#include "../includes/checker.h"

void	push_b(t_data *db, int print)
{
	if (db->top_a < 0)
		return ;
	db->top_b++;
	db->sb[db->top_b] = db->sa[db->top_a];
	db->top_a--;
	if (print)
		write(1, "pb\n", 3);
}

void    rotate_b(t_data *db, int print)
{
	int	temp;
	int	i;

	if (db->top_b <= 0)
		return ;
	i = db->top_b;
	temp = db->sb[db->top_b];
	while (i > 0)
	{
		db->sb[i] = db->sb[i - 1];
		i--;
	}
	db->sb[i] = temp;
	if (print)
		write (1, "rb\n", 3);
}

void    rotate_r_b(t_data *db, int print)
{
	int	temp;
	int	i;

	if (db->top_b <= 0)
		return ;
	temp = db->sb[0];
	i = 0;
	while (i < db->top_b)
	{
		db->sb[i] = db->sb[i + 1];
		i++;
	}
	db->sb[db->top_b] = temp;
	if (print)
		write(1, "rrb\n", 4);
}

void    swap_b(t_data *db, int print)
{
	int	temp;

	if (db->top_b < 1)
		return ;
	temp = db->sb[db->top_b];
	db->sb[db->top_b] = db->sb[db->top_b - 1];
	db->sb[db->top_b - 1] = temp;
	if (print)
		write(1, "sb\n", 3);
}
