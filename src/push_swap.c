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
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	db;
	char	**tab;

	if (argc == 1)
		return (0);
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
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
//	int i = db.top_a;
//	printf("Before sorting\n");
//	while (i >= 0)
//	{
//		printf("position %d: %d\n", i, db.sa[i]);
//		i--;
//	}
	if (!(is_sorted(&db)))
		sorting_stack(&db);
	//printf("top a: %d\n", db.top_a);
//	i = db.top_a;
//	printf("After sorting\n");
//	while (i >= 0)
//	{
//		printf("position %d: %d\n", i, db.sa[i]);
//		i--;
//	}
	free_all_and_exit(&db, 0);
	return (0);
}
