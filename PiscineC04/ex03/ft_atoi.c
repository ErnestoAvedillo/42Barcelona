#include <stdio.h>
int	get_first_nbr (char *str)
{
	int	count;
	int	sign;

	sign = 1;
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 48 && str[count] <= 57)
			return (count * sign);
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	return (count * sign);

}
int	ft_atoi(char *str)
{
	int	count;
	int first_nbr;
	int result;
	int pot;
	int sign;

	result = 0;
	first_nbr = get_first_nbr(str);
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