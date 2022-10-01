#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strlen()
{
	/*ft_strlen
	 */
	char str[50] = "qwerty";
	printf("test ft_strlen\n");
	printf("La longitud de la cadena deberia ser %lu y me sale %lu\n\n", strlen(str), ft_strlen(str));

}