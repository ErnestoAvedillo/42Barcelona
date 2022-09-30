#include "../Libft/libft.h"
#include "test_lib.h"

void test_ft_strlen()
{
	/*ft_strlen
	 */
	char str[50] = "qwerty";
	printf("test ft_strlen\n");
	printf("La longitud de la cadena deberia ser %u y me sale %u\n\n", strlen(str), ft_strlen(str));

}