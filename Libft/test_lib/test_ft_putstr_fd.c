#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_putstr_fd ()
{
	char str[50] = "Tengo un paquete para ti";
	/*ft_putstr_fd
	 */
	printf("%stest de ft_putstr_fd%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_putstr_fd(str,1);
	printf("\n");
}