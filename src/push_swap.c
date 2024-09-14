/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:21 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/04 12:27:47 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_tab_two(char **argv, t_data *db)
{
	if (!argv[1][0] || argv[1][0] == 32 || (argv[1][0] >= 9 && argv[1][0] <= 13))
	{
		write(2, "Incorrect arguments.\n", 21);
		exit (1);
	}
	db->tab = ft_split(argv[1], ' ');
	if (db->tab == NULL)
	{
		write(2, "Tab allocation failed\n", 22);
		exit (1);
	}
	db->is_tab_all = 1;
}

int	main(int argc, char *argv[])
{
	t_data	db;

	if (argc == 1)
		return (0);
	if (argc == 2)
		create_tab_two(argv, &db);
	else
	{
		db.tab = &argv[1];
		db.is_tab_all = 0;
	}	
	error_check(&db, db.tab);
	initialize_values(&db);
	if (!(is_sorted(db.head_a)))
		sorting_stack(&db);
	free_all(&db);	
	return (0);
}
