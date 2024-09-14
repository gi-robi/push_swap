#include "../includes/push_swap.h"

void	rotate_both(t_node **head_a, t_node **head_b)
{
	rotate_a(head_a, 0);
	rotate_b(head_b, 0);
	write (1, "rr\n", 3);
}

void	swap_both(t_node **head_a, t_node **head_b)
{
	swap_a(head_a, 0);
	swap_b(head_b, 0);
	write(1, "ss\n", 3);
}

void	rotate_r_both(t_node **head_a, t_node **head_b)
{
	rotate_r_a(head_a, 0);
	rotate_r_b(head_b, 0);
	write(1, "rrr\n", 4);
}
