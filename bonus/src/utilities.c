/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:46:46 by rgiambon          #+#    #+#             */
/*   Updated: 2024/09/16 15:46:48 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

long long	ft_atoi_ps(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*str;
	int		i;

	size = ft_strlen(s) + 1;
	str = (char *)malloc(size);
	if (str == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	unsigned int	j;
	unsigned int	actual_len;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	actual_len = ft_strlen(s + start);
	if (len > actual_len)
		len = actual_len;
	i = start;
	substr = (char *)malloc(len + 1);
	if (substr == 0)
		return (0);
	j = 0;
	while (i < start + len && s[i])
	{
		substr[j++] = s[i++];
	}
	substr[j] = '\0';
	return (substr);
}
