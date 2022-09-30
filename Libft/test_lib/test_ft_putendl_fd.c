#include "../Libft/libft.h"
#include "test_lib.h"

void test_ft_putendl_fd ()
{
	char str[50] = "Tengo un paquete para ti";
	/*ft_putendl_fd
	 */
	printf("Test de ft_putendl_fd :\n");
	ft_putendl_fd(str,1);
	printf("\n");
}