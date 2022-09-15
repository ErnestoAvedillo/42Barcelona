#include <stdio.h>
#include "C05.h"

int main(void)
{
	int val = 9;
	int power =4;
	int ret;

	ft_ten_queens_puzzle();
	ret = ft_iterative_factorial(val);
	printf("El factorial de %d es %d\n",val , ret);

	ret = ft_recursive_factorial(val);
	printf("El factorial de %d es %d\n",val , ret);

	ret = ft_iterative_power(val, power);
	printf("La potencia de %d a la %d es %d\n",val, power, ret);

	ret = ft_recursive_power(val, power);
	printf("La potencia de %d a la %d es %d\n",val, power, ret);

	ret = ft_fibonacci(val);
	printf("El fibonazi de posición %d es %d\n",val , ret);

	ret = ft_sqrt(val);
	printf("La raiz de  %d es %d\n",val , ret);
	ret = ft_sqrt(11);
	printf("La raiz de  %d es %d\n",11 , ret);


	ret = ft_is_prime(11);
	printf("El Valor  %d es primo (1:Si, 0:no) %d\n",11 , ret);

	ret = ft_is_prime(27);
	printf("El Valor  %d es primo (1:Si, 0:no) %d\n",27 , ret);

	ret = ft_find_next_prime(31);
	printf("El Próximo primo de %d es %d\n",31 , ret);

	return (0);
}
