/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:21 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 14:59:37 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_data	db;

	if (argc == 1)
		return (0);
	if (error_check(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	initialize_values(&db, argv);
	if (are_not_sorted(&db))
		sorting_stack(&db);
	return (0);
}
