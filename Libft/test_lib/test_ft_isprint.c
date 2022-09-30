#include "../Libft/libft.h"
#include "test_lib.h"

void test_ft_isprint()
{
	/* ft_isprint
	*/
	char var3 = 'r';
	int var4 = 177;
	printf("test ft_sprint\n");
	printf("ft_sprint para %c retorna %d\n", var3, ft_isprint(var3));
	printf("sprint para %c retorna %d\n", var3, isprint(var3));
	printf("ft_sprint para %d retorna %d\n", var4, ft_isprint(var4));
	printf("sprint para %d retorna %d\n", var4, isprint(var4));
	printf("\n");

}