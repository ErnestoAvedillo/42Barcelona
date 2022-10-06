#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_putchar_fd ()
{
	char var1 = 'r';
	/*ft_putchar_fd
	*/
	printf("%stest de ft_putchar_fd%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	printf("Test de ft_putchar_fd :\n");
	ft_putchar_fd(var1,1);
	printf("\n");

}