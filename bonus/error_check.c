int	is_sorted(t_data *db)
{
	int	i;
	
	i = 0;
	while (i < db->top_a)
	{
		if (db->sa[i] < db->sa[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_not_digit(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		//handle negative numbers
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_over_limits(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi_ps(argv[i]) > INT_MAX || ft_atoi_ps(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	is_double_number(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi_ps(argv[i]) == ft_atoi_ps(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check(char *argv[])
{
	if (is_not_digit(argv))
		return (1);
	if (is_over_limits(argv))
		return (1);
	if (is_double_number(argv))
		return (1);
	
	return (0);
}
