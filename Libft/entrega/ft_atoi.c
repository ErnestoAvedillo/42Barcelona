/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 12:01:16 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static int	get_first_nbr(char *str)
{
	int	count;
	int	sign;

	sign = 1;
	count = 0;
	while (str[count] == ' ' || \
		str[count] == '\t' || \
		str[count] == '\n' || \
		str[count] == '\r' || \
		str[count] == '\v' || \
		str[count] == '\f' )
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	if (!ft_isdigit(str[count]))
		return (0);
	return (count * sign);
}

static int	get_last_nbr(const char *s, int i)
{
	while (s[i + 1] >= 48 && \
			s[i + 1] <= 57 && \
			s[i + 1] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	count;
	int	first_nbr;
	int	result;
	int	pot;
	int	sign;

	result = 0;
	first_nbr = get_first_nbr ((char *)(str));
	if (first_nbr == 0 && !ft_isdigit(str[0]))
		return (0);
	sign = 1;
	if (first_nbr < 0)
		sign = -1;
	first_nbr = first_nbr * sign;
	count = get_last_nbr(str, first_nbr);
	pot = 1;
	while (count >= first_nbr)
	{
		result += (str[count] - '0') * pot;
		pot *= 10;
		count--;
	}
	return (result * sign);
}
