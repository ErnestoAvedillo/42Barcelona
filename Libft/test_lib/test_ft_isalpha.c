#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_isalpha()
{
	/* ft_isalpha
	*/
	int var1 = 'r';
	int var2 = 'R';
	int var3 = '2';
	printf("test ft_isalpha\n");
	printf("ft_isalpha para %c retorna %d\n", var1, ft_isalpha(var1));
	printf("isalpha para %c retorna %d\n", var1, isalpha(var1));
	printf("ft_isalpha para %c retorna %d\n", var2, ft_isalpha(var2));
	printf("isalpha para %c retorna %d\n", var2, isalpha(var2));
	printf("ft_isalpha para %c retorna %d\n", var3, ft_isalpha(var3));
	printf("isalpha para %c retorna %d\n", var3, isalpha(var3));
	printf("\n");
}