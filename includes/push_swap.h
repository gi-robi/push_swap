/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:04:18 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/04 12:35:24 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int	value;
	int	index;
	int	price;
	int	is_below_middle;
	int	is_cheapest;
	struct s_node *target_node;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

typedef struct s_data
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*end_a;
	char	**tab;
	int	middle;
	int	is_tab_all;
}	t_data;

//error checking functions
int	error_check(t_data *db, char **tab);
int	is_double_number(char **tab);
int	is_over_limits(char **tab);
int	is_not_digit(char **tab);
int	is_sorted(t_node *head);
//create stack functions
void	initialize_values(t_data *db);
//operations of stack A
void    swap_a(t_node **head, int print);
void    rotate_a(t_node **head, int print);
void    rotate_r_a(t_node **head, int print);
void    push_a(t_data *db);
//operations of stack B
void    push_b(t_data *db);
void    rotate_b(t_node **head, int print);
void    rotate_r_b(t_node **head, int print);
void    swap_b(t_node **head, int print);
//operations both
void    swap_both(t_node **head_a, t_node **head_b);
void    rotate_both(t_node **head_a, t_node **head_b);
void    rotate_r_both(t_node **head_a, t_node **head_b);
//sorting stack
void	sorting_stack(t_data *db);
void    sort_3(t_node **head, t_data *db);
void    sort_all(t_data *db);

//utilities
long long	ft_atoi_ps(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char    	*ft_strdup(const char *s);
size_t		ft_strlen(const char *string);
//list utilities
void	create_tab_two(char **argv, t_data *db);
void    store_middle(t_data *db);
void    put_node_end(t_node **head, t_node **end, int num, t_data *db);
void    make_move(t_node **head_a, t_node **head_b, t_data *db);
void    continue_rotation(t_node **head, t_node *cheapest, char stack);
int     len_of_list(t_node *head);
t_node	*get_last_node(t_node *head);
void	get_place_in_list(t_node *head);
void	get_values(t_data *db);
void	final_adjustments(t_data *db);
t_node  *get_smallest(t_node *head);
void    get_cheapest(t_node *head);
void    get_target_node(t_node *head_a, t_node *head_b);
t_node  *get_cheapest_node(t_node *head);
//free memory
void    free_all(t_data *db);
void	free_tab(t_data *db);
void    free_stack(t_node **head);

#endif
