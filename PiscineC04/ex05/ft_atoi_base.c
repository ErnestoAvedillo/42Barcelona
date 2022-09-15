#include <stdio.h>
#include <unistd.h>

int	get_pos_base (char c,char *base)
{
	int	count;

	count = 0;
	while(c != base[count] )
	{
		if (base[count] == '\0')
			return (-1);
		count++;
	}
	return (count);
}
/*
int	is_in_base(char c, char *base)
{
	while (base)
	{
		if (*base == c)
			return (1);
		base++;
	}
	return(-1);
}
*/
int	get_first_pos (char *str, char *base)
{
	int	count;
	int	sign;

	sign = 1;
	count = 0;
	while (str[count] != '\0')
	{
		if (get_pos_base(str[count], base) >= 0)
			return (count * sign);
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	return (count * sign);
}

int	get_last_pos (int first_pos, char *str, char *base)
{
	int	count;

	count = first_pos;
	while (get_pos_base(str[count + 1], base) >= 0 && str[count + 1] != '\0' )
		 count++;
	return (count);
}

int detect_base_err_atoi (char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == ' ' || base[i] == '-') 
		{
			write (1,"caracter prohibido", 18);
			write(1, &base[i], 1);
			write(1, "\n", 1);				

			return (1);
		}	
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				write(1, "letra repe ", 11);
				write(1, &base[j], 1);
				write(1, "\n", 1);				
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
int	get_len_base_atoi (char *base)
{
	int	count;

	count = 0;
	while (base[count] != '\0')
		count++;
	return (count);
}

int	convert_to_base(int pos_start, int pos_end, char *str, char *base, int base_nbr)
{
	int	ret_val;
	int	count;
	int	grup_nbr;
	printf("base = %d\n", base_nbr);
	grup_nbr = 1;
	count = pos_end;
	ret_val = 0;
	while(count >= pos_start)
	{
		ret_val += grup_nbr * get_pos_base(str[count], base);
		grup_nbr *= base_nbr; 
		count--;
	}
	return(ret_val);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_nbr;
	int	pos_start;
	int	pos_end;
	int	negativo;

	negativo = 1;
	base_nbr = get_len_base_atoi(base);
	if (base_nbr <= 1)
		return (0);
	if (detect_base_err_atoi(base))
		return(0);
	pos_start = get_first_pos(str, base);
	if (pos_start < 0)
		negativo = -1;
	pos_start = pos_start * negativo;
	pos_end = get_last_pos(pos_start, str, base); 
	printf("\n%s\n","paso" );
	return (negativo * convert_to_base(pos_start, pos_end, str, base, base_nbr));	
}