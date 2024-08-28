int	find_smallest(int *stack, int s_top)
{
	int min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i <= s_top)
	{
		if (stack[min_index] > stack[i])
			min_index = i;
		i++;
	}
	return (min_index);
}	
