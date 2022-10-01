#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_toupper()
{
	/*ft_toupper
	 */
	char	var1 = 'r';
	char	var2 = 'R';
	char	var3 = '2';
	printf("test ft_toupper\n");
	printf("var1 %d var2 %d var3 %d \n", var1, var2, var3);
	printf("ft_toupper para %c retorna %d\n", var1, ft_toupper(var1));
	printf("toupper para %c retorna %d\n", var1, toupper(var1));
	printf("ft_toupper para %c retorna %d\n", var2, ft_toupper(var2));
	printf("toupper para %c retorna %d\n", var2, toupper(var2));
	printf("ft_toupper para %c retorna %d\n", var3, ft_toupper(var3));
	printf("toupper para %c retorna %d\n", var3, toupper(var3));
	printf("\n");
}