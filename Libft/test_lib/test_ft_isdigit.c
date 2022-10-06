#include "../entrega/libft.h"
#include "test_lib.h"

	/*ft_isdigit
	 */
void test_ft_isdigit()
{
	int var1 = 'r';
	int var2 = 'R';
	int var3 = '2';

	printf("%stest ft_isdigit%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	printf("ft_isdigit para %c retorna %d\n", var1, ft_isdigit(var1));
	printf("isdigit para %c retorna %d\n", var1, isdigit(var1));
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_isdigit para %c retorna %d\n", var2, ft_isdigit(var2));
	printf("isdigit para %c retorna %d\n", var2, isdigit(var2));
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("ft_isdigit para %c retorna %d\n", var3, ft_isdigit(var3));
	printf("isdigit para %c retorna %d\n", var3, isdigit(var3));
	printf("\n");
}