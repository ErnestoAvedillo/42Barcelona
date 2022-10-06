#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_toupper()
{
	/*ft_toupper
	 */
	char	var1 = 'r';
	char	var2 = 'R';
	char	var3 = '2';
	printf("%sTest de ft_toupper%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	printf("var1 %d var2 %d var3 %d \n", var1, var2, var3);
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_toupper para %c retorna %d\n", var1, ft_toupper(var1));
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("toupper para %c retorna %d\n", var1, toupper(var1));
	printf("%sTest4%s\n",KYEL, KNRM);
	printf("ft_toupper para %c retorna %d\n", var2, ft_toupper(var2));
	printf("%sTest5%s\n",KYEL, KNRM);
	printf("toupper para %c retorna %d\n", var2, toupper(var2));
	printf("%sTest6%s\n",KYEL, KNRM);
	printf("ft_toupper para %c retorna %d\n", var3, ft_toupper(var3));
	printf("%sTest7%s\n",KYEL, KNRM);
	printf("toupper para %c retorna %d\n", var3, toupper(var3));
	printf("\n");
}