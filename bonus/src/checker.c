/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:43:05 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 17:04:02 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	sort_loop(t_data *db)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			return ;
		sort_tab(move, db);
		if (db->spelling_error)
		{
			write(2, "Error\n", 6);
			return ;
		}
		free(move);
	}
}

void	sort_tab(char *move, t_data *db)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap_a(db, 0);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap_b(db, 0);
	else if (ft_strcmp(move, "ss\n") == 0)
		swap_both(db);
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate_a(db, 0);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate_b(db, 0);
	else if (ft_strcmp(move, "rr\n") == 0)
		rotate_both(db);
	else if (ft_strcmp(move, "rra\n") == 0)
		rotate_r_a(db, 0);
	else if (ft_strcmp(move, "rrb\n") == 0)
		rotate_r_b(db, 0);
	else if (ft_strcmp(move, "rrr\n") == 0)
		rotate_r_both(db);
	else if (ft_strcmp(move, "pa\n") == 0)
		push_a(db, 0);
	else if (ft_strcmp(move, "pb\n") == 0)
		push_b(db, 0);
	else
		db->spelling_error = 1;
}

void	check_if_sorted(t_data *db, char **tab)
{
	if (is_sorted(db) && db->top_b == -1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	if (db->is_tab_all)
		free_tab(tab);
}

int	main(int argc, char **argv)
{
	t_data	db;
	char	**tab;

	db.is_tab_all = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		db.is_tab_all = 1;
	}
	else
		tab = argv + 1;
	if (error_check(tab))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	initialize_values(&db, tab);
	if (db.sa == NULL || db.sb == NULL)
		return (0);
	sort_loop(&db);
	check_if_sorted(&db, tab);
	free_stacks(&db);
	return (0);
}
