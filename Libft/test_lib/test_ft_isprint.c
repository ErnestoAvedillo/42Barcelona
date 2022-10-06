#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_isprint()
{
	/* ft_isprint
	*/
	char var3 = 'r';
	int var4 = 177;
	printf("%stest ft_sprint%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	printf("ft_sprint para %c retorna %d\n", var3, ft_isprint(var3));
	printf("sprint para %c retorna %d\n", var3, isprint(var3));
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_sprint para %d retorna %d\n", var4, ft_isprint(var4));
	printf("sprint para %d retorna %d\n", var4, isprint(var4));
	printf("%sTest3%s\n",KYEL, KNRM);
	var4 = ' ';
	printf("ft_isprint para %d retorna %d\n", var4, ft_isprint(var4));
	printf("isprint para %d retorna %d\n", var4, isprint(var4));
	printf("\n");

}