#include "../includes/push_swap_bonus.h"

void	free_all(char **moves)
{
	int	i;
	
	i = 0;
	while (moves[i])
	{
		free(moves[i]);
		i++;
	}
	free(moves);
	moves = NULL;
}

void	read_input(char **moves)
{
	int	fd;
	int	strings_count;
	int	i;

	i = 0;
	strings_count = strings_counter(0);
	moves = malloc((strings_count + 1) * sizeof(char *));
	if (moves == NULL)
		return;
	while (i < strings_count)
	{
		moves[i] = get_next_line(fd);
		if (moves[i] == NULL)
		{
			free_all(moves);
			return ;
		}
		i++;
	}
	moves[i] = NULL;
}

void	sort_tab(char **moves, t_data *db)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (ft_strcmp(moves[i], "sa\n") == 0)
			swap_a(db, 0);
		if (ft_strcmp(moves[i], "sb\n") == 0)
			swap_b(db, 0);
		if (ft_strcmp(moves[i], "ss\n") == 0)
			swap_both(db, 0);
		if (ft_strcmp(moves[i], "ra\n") == 0)
			rotate_a(db, 0);
		if (ft_strcmp(moves[i], "rb\n") == 0)
			rotate_b(db, 0);
		if (ft_strcmp(moves[i], "rr\n") == 0)
			rotate_both(db, 0);
		if (ft_strcmp(moves[i], "rra\n") == 0)
			rotate_r_a(db, 0);
		if (ft_strcmp(moves[i], "rrb\n") == 0)
			rotate_r_b(db, 0);
		if (ft_strcmp(moves[i], "rrr\n") == 0)
			rotate_r_both(db, 0);
		if (ft_strcmp(moves[i], "pa\n") == 0)
			push_a(db, 0);
		if (ft_strcmp(moves[i], "pb\n") == 0)
			push_b(db, 0);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	db;
	int	**tab;
	char	**moves;

	if (argc == 1)
		return (0);
	if (argc == 2)
		tab = ft_split(argv, ' ');
	else
		tab = argv + 1;
	//add error check
	initialize_values(tab, db);
	if (db->sa == NULL || db->sb == NULL)
		return (0);
	read_input(moves);
	if (moves == NULL)
		return (0);
	sort_tab(moves, &db);
	if (is_sorted(db) && db.top_b == -1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
	
