#include "../entrega/libft.h"
#include "test_lib.h"

	/* ft_isalnum
	*/
void test_ft_isalnum()
{
	int var1 = 'r';
	int var2 = 'R';
	int var3 = '2';
	int var4 = '\n';
	printf("%stest ft_isalnum%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	printf("ft_isalnum para %c retorna %d\n", var1, ft_isalnum(var1));
	printf("isalnum para %c retorna %d\n", var1, isalnum(var1));
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_isalnum para %c retorna %d\n", var2, ft_isalnum(var2));
	printf("isalnum para %c retorna %d\n", var2, isalnum(var2));
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("ft_isalnum para %c retorna %d\n", var3, ft_isalnum(var3));
	printf("isalnum para %c retorna %d\n", var3, isalnum(var3));
	printf("%sTest4%s\n",KYEL, KNRM);
	printf("ft_isalnum para %c retorna %d\n", var4, ft_isalnum(var4));
	printf("isalnum para %c retorna %d\n", var4, isalnum(var4));
	printf("\n");
}