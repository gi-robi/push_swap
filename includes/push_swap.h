/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:04:18 by rgiambon          #+#    #+#             */
/*   Updated: 2024/08/27 15:23:32 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_data
{
	int	*sa;
	int	*sb;
	int	lenght;
	int	top_a;
	int	top_b;
}	t_data;

//error checking functions
int		error_check(char *argv[]);
int		is_double_number(char *argv[]);
int		is_over_limits(char *argv[]);
int		is_not_digit(char *argv[]);
//create stack functions
void	create_stack(t_data *db, char *argv[]);
void	fill_stack(t_data *db, char *argv[]);
int		get_stack_lenght(char *argv[]);

#endif
