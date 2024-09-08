#include "../includes/checker.h"

void	rotate_both(t_data *db)
{
	rotate_a(db, 0);
	rotate_b(db, 0);
	write (1, "rr\n", 3);
}

void	swap_both(t_data *db)
{
	swap_a(db, 0);
	swap_b(db, 0);
	write(1, "ss\n", 3);
}

void	rotate_r_both(t_data *db)
{
	rotate_r_a(db, 0);
	rotate_r_b(db, 0);
	write(1, "rrr\n", 4);
}
