#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_bzero()
{
	/*ft_bzero
	 */
	char str[50];
	
	printf("%stest ft_bzero%s\n",KGRN, KNRM);
	ft_strlcpy(str, "esto es un atraco",17);
	printf ("Antes de bzero el texto es: %s.\n " , str);
//	bzero(str, 9);
	printf ("Despues de bzero el texto es %s.\n " , str);
	ft_strlcpy(str, "esto es un atraco",17);
	printf("Antes de ft_bzero el texto es: %s.\n", str);
	ft_bzero(str,5 );
	printf ("Despues de ft_bzero el texto es: %s.\n\n" , str);
	printf("\n");
}