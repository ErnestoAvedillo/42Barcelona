#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_tolower()
{
	/*ft_tolower
	 */
	char	var1 = 'r';
	char	var2 = 'R';
	char	var3 = '2';
	printf("%sTest de ft_tolower%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	printf("var1 %d var2 %d var3 %d \n", var1, var2, var3);
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_tolower para %c retorna %d\n", var1, ft_tolower(var1));
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("tolower para %c retorna %d\n", var1, tolower(var1));
	printf("%sTest4%s\n",KYEL, KNRM);
	printf("ft_tolower para %c retorna %d\n", var2, ft_tolower(var2));
	printf("%sTest5%s\n",KYEL, KNRM);
	printf("tolower para %c retorna %d\n", var2, tolower(var2));
	printf("%sTest6%s\n",KYEL, KNRM);
	printf("ft_tolower para %c retorna %d\n", var3, ft_tolower(var3));
	printf("%sTest7%s\n",KYEL, KNRM);
	printf("tolower para %c retorna %d\n", var3, tolower(var3));
	printf("\n");
}