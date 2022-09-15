#include <unistd.h>
#include <stdio.h>


int detect_base_err (char *base)
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

int get_len_base (char *base)
{
	int count;

	count = 0;
	while (base[count] != '\0')
		count++;
	return (count-1);
}

void print_nbr (int nbr, char *base,int base_nbr)
{
	int count;
	int n;
	count = nbr / base_nbr;
	if(count != 0)
	{
		print_nbr(nbr / base_nbr, base, base_nbr);
	}
	n = nbr % base_nbr;
	write(1, &base[n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_nbr;

	base_nbr = get_len_base(base);
	if (base_nbr <= 1)
		return;
	if (detect_base_err(base))
		return;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	print_nbr(nbr, base, base_nbr);
}
