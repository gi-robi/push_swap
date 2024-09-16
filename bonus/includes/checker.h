/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:38:45 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 17:04:30 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int	*sa;
	int	*sb;
	int	lenght;
	int	top_a;
	int	top_b;
	int	spelling_error;
	int	is_tab_all;
}	t_data;

long long	ft_atoi_ps(const char *str);
void		fill_new_list(t_list *tmp, t_list *new_list);
char		*get_next_line(int fd);
void		read_and_putnode(int fd, t_list **list);
int			new_line(t_list **list);
t_list		*add_new_node(t_list **list, int is_new_list);
void		reset_list(t_list **list);
void		free_all(t_list **list);
void		fill_line(t_list *list, char *line, int line_len);
void		remove_last_node(t_list **list);
int			count_len(t_list **list);
void		sort_tab(char *move, t_data *db);
void		check_if_sorted(t_data *db, char **tab);
void		sort_loop(t_data *db);
int			error_check(char *argv[]);
int			is_double_number(char *argv[]);
int			is_over_limits(char *argv[]);
int			is_not_digit(char *argv[]);
int			is_sorted(t_data *db);
char		**ft_split(char const *s, char c);
void		initialize_values(t_data *db, char *argv[]);
void		fill_stack(t_data *db, char *argv[]);
int			get_stack_lenght(char *argv[]);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *string);
int			ft_strcmp(char *s1, char *s2);
void		rotate_both(t_data *db);
void		swap_both(t_data *db);
void		rotate_r_both(t_data *db);
void		swap_b(t_data *db, int print);
void		rotate_r_b(t_data *db, int print);
void		rotate_b(t_data *db, int print);
void		push_b(t_data *db, int print);
void		swap_a(t_data *db, int print);
void		rotate_a(t_data *db, int print);
void		rotate_r_a(t_data *db, int print);
void		push_a(t_data *db, int print);
void		free_tab(char **tab);
void		free_stacks(t_data *db);

#endif
