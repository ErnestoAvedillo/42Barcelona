#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strlen()
{
	/*ft_strlen
	 */
	printf("%sTest de ft_strlen%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	char str[50] = "qwerty";
	printf("La longitud de la cadena deberia ser %lu y me sale %lu\n\n", strlen(str), ft_strlen(str));

}