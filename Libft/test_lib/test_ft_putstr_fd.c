#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_putstr_fd ()
{
	char str[50] = "Tengo un paquete para ti";
	/*ft_putstr_fd
	 */
	printf("Test de ft_putstr_fd :\n");
	ft_putstr_fd(str,1);
	printf("\n");
}