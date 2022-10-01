#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_tolower()
{
	/*ft_tolower
	 */
	char	var1 = 'r';
	char	var2 = 'R';
	char	var3 = '2';
	printf("test ft_tolower\n");
	printf("var1 %d var2 %d var3 %d \n", var1, var2, var3);
	printf("ft_tolower para %c retorna %d\n", var1, ft_tolower(var1));
	printf("tolower para %c retorna %d\n", var1, tolower(var1));
	printf("ft_tolower para %c retorna %d\n", var2, ft_tolower(var2));
	printf("tolower para %c retorna %d\n", var2, tolower(var2));
	printf("ft_tolower para %c retorna %d\n", var3, ft_tolower(var3));
	printf("tolower para %c retorna %d\n", var3, tolower(var3));
	printf("\n");
}