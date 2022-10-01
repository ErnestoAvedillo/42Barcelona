#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_memset()
{
	/*ft_memset
	 */
	char str[50] = "qwerty";
	printf("test ft_memset\n");
	printf("Antes de memset es : %s\n", str);
	memset(str, '*', 8 * sizeof(char));
	printf("despues de memset es : %s\n", str);
	memset(str, '-', 8 * sizeof(char));
	printf("despues de ft_memset es : %s\n\n", str);

}