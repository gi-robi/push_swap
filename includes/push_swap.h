/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:04:18 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/04 12:05:27 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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
int	are_not_sorted(t_data *db);
//create stack functions
void	initialize_values(t_data *db, char *argv[]);
void	fill_stack(t_data *db, char *argv[]);
int		get_stack_lenght(char *argv[]);
//operations of stack A
void    swap_a(t_data *db);
void    rotate_a(t_data *db);
void    rotate_r_a(t_data *db);
void    push_a(t_data *db);
//operations of stack B
void    push_b(t_data *db);
//sorting stack
void	sorting_stack(t_data *db);
void    sort_3(t_data *db);
void    sort_4(t_data *db);
void    sort_5(t_data *db);
void    sort_100(t_data *db);
//utilities
int	find_smallest(int *stack, int s_top);
long long	ft_atoi_ps(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
