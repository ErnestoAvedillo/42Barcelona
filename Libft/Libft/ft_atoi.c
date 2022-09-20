/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 18:18:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

static int	get_first_nbr (char *str)
{
	int	count;
	int	sign;

	sign = 1;
	count = 0;
	while (str[count] != '\0' && (str[count] = ' ' || str[count] == '-'))
	{
		if (str[count] == '-' && sign == -1)
			return (0);
		else 
			sign *= -1;
		count++;
	}
	if (str[count] >= 48 && str[count] <= 57)
		return (0);
	return (count * sign);

}
int	ft_atoi(const char *str)
{
	int	count;
	int first_nbr;
	int result;
	int pot;
	int sign;

	result = 0;
	first_nbr = get_first_nbr((char*)(str));
	if (first_nbr == 0)
	{
		printf("2 %c\n", str[0]);
		return (0);
	}
	sign = 1;
	if (first_nbr < 0)
		sign = -1;
	first_nbr = first_nbr * sign;
	count = first_nbr;
	while (str[count + 1] >= 48 && str[count + 1] <= 57 && str[count + 1] != '\0')
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

