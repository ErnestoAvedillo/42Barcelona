/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/23 21:21:34 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

static int	get_first_nbr(char *str)
{
	int	count;
	int	sign;
	int	start;

	sign = 1;
	start = 0;
	count = 0;
	while (str[count] == ' ')
	{
		count++;
		start++;
	}
	if (str[count] == '-')
	{
		sign = -1;
		if (!ft_isdigit(str[++count]))
			return (0);
		start++;
	}
	return (start * sign);
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
	if (first_nbr == 0)
		return (0);
	sign = 1;
	if (first_nbr < 0)
		sign = -1;
	first_nbr = first_nbr * sign;
	count = first_nbr;
	while (str[count + 1] >= 48 && \
			str[count + 1] <= 57 && \
			str[count + 1] != '\0')
		count++;
	pot = 1;
	while (count >= first_nbr)
	{
		result += (str[count] - '0') * pot;
		pot *= 10;
		count--;
	}
	return (result * sign);
}
