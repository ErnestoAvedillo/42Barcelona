#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strlcpy()
{
	/*ft_strlcpy
	 */
	int val = 10;
	printf("%sTest de ft_strlcpy%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	char str[50] ="esto es un atraco asqueroso";
	printf("La cadena era >%s\n<",str);
//	strlcpy (str, "pepito grillo", 10);	
	printf("La cadena con strlcpy es >%s<\n",str);
	ft_strlcpy(str, "pepito grillo", val);
	printf("La cadena con mi ft_strlcpy copio %d caracteres y resulta >%s<\n",val, str);
	printf("\n");

}