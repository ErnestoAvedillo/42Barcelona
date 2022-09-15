#include <unistd.h>
#include <stdio.h>
int abs (int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int is_ten_queen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while ( str[i] != '\0')
	{
		j = i + 1;
		while ( str[j] != '\0')
		{
			//printf("%d -- %d \n", abs(j - i), abs(str[i] - str [j]));
			if (abs(j - i) == abs(str[i] - str [j]))
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}

int	len_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	rm_char(char *str_out, char *str, int nb)
{
	int		count;
	int		long_str;

	long_str = len_str(str);
	count = 0;
	while (count < long_str)
	{
		if (count < nb)
			str_out[count] = str[count];
		else if (count > nb)
			str_out[count-1] = str[count];
		count++;
	}
	str_out[count-1] = '\0';

	return;
}
/*
void permutacion (char *str, int nb, int my_strlen)
{
	int		i;
	char	aux;


	if (nb == my_strlen - 1)
	{
		//if (is_ten_queen(str))
		//{
			write(1, str, my_strlen);
			write(1, "\n", 1);
		//}
	}
	else
	{
		i = nb;
		while (i <= my_strlen - 1)
		{			
			aux = str[nb];
			str[nb] = str[i];
			str[i] = aux;
			permutacion(str, nb+1, my_strlen);
			aux = str[nb];
			str[nb] = str[i];
			str[i] = aux;	
			i++;
		}
	}
}
*/
void permutacion_ea (char *str_prev, int n_prev, char *str_post, int n_post)
{
	int		i;
	char	str_aux[11] = "0123456789";

	if (n_post == 1)
	{
		str_prev[n_prev] = str_post [0];
		if (is_ten_queen(str_prev))
		{
			//printf("%d--%d n_prev y post prefio final\n",n_prev,n_post);
			//printf("%s--%s antes asignacion final\n",str_prev,str_post);
			//printf("%s--%s tras asignacion final\n",str_prev,str_post);
			//str_prev[n_prev + 1] = '\n';			
			write(1, str_prev, n_prev+1);
			write(1, "\n", 1);
			//printf("%s final\n",str_prev );
		}
	}
	else
	{
		i = 0;
		while (i < n_post)
		{
			str_prev[n_prev] = str_post [i];
			str_prev[n_prev + 1] = '\0';
			//printf("%d--%d intermedio\n",n_prev,n_post);
			//printf("%s--%s intermedio\n",str_prev,str_post);
			//str_prev[n_prev + 1] = '\n';			
			rm_char(str_aux, str_post, i);
			//printf("%s--%s tras rm_char\n",str_aux,str_post);
			permutacion_ea(str_prev, n_prev + 1, str_aux, n_post - 1);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char str_post[11] = "0123456789";
	char str_prev[11] = "0123456789";
	int my_strlen;

	my_strlen = len_str(str_post);
	permutacion_ea (str_prev, 0, str_post, my_strlen);
	return(0);
//	printf("%d\n", is_ten_queen("0257948136") );
}

 