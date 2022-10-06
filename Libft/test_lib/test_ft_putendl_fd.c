#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_putendl_fd ()
{
	char str[50] = "Tengo un paquete para ti";
	/*ft_putendl_fd
	 */
	printf("%stest de ft_putendl_fd%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_putendl_fd(str,1);
	printf("\n");
}