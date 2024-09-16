/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:46:05 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 15:46:09 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate_both(t_data *db)
{
	rotate_a(db, 0);
	rotate_b(db, 0);
}

void	swap_both(t_data *db)
{
	swap_a(db, 0);
	swap_b(db, 0);
}

void	rotate_r_both(t_data *db)
{
	rotate_r_a(db, 0);
	rotate_r_b(db, 0);
}
