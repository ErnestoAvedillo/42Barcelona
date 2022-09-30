#include "../Libft/libft.h"
#include "test_lib.h"

	/*ft_isdigit
	 */
void test_ft_isdigit()
{
	int var1 = 'r';
	int var2 = 'R';
	int var3 = '2';

	printf("test ft_isdigit\n");
	printf("ft_isdigit para %c retorna %d\n", var1, ft_isdigit(var1));
	printf("isdigit para %c retorna %d\n", var1, isdigit(var1));
	printf("ft_isdigit para %c retorna %d\n", var2, ft_isdigit(var2));
	printf("isdigit para %c retorna %d\n", var2, isdigit(var2));
	printf("ft_isdigit para %c retorna %d\n", var3, ft_isdigit(var3));
	printf("isdigit para %c retorna %d\n", var3, isdigit(var3));
	printf("\n");
}