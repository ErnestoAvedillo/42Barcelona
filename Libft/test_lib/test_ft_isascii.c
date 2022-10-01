#include "../entrega/libft.h"
#include "test_lib.h"

	/* ft_isacii
	*/
void test_ft_isascii()
{
	char var3 = 'r';
	char var4 = 178;
	printf("test ft_isacii\n");
	printf("ft_isacii para %c retorna %d\n", var3, ft_isascii(var3));
	printf("isacii para %c retorna %d\n", var3, isascii(var3));
	printf("ft_isacii para %d retorna %d\n", var4, ft_isascii(var4));
	printf("isacii para %d retorna %d\n", var4, isascii(var4));
	printf("\n");

}