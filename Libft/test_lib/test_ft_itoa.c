#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_itoa ()
{
	char	*ptr;
	int		var1;;
	/*ft_itoa
	*/

	printf("test ft_itoa\n");
	var1 = 14567;
	ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str -%s- en el puntero %p\n", var1, ptr, ptr);
	free(ptr);
	var1 = -4567;
	ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str -%s- en el puntero %p\n", var1, ptr, ptr);
	printf("\n");
	free(ptr);
}