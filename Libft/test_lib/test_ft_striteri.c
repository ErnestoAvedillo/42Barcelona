#include "../entrega/libft.h"
#include "test_lib.h"

void	ft_test_iteri(unsigned int i, char *c)
{
	i += 1;
	*c += 32;
	return;
}

void test_ft_striteri ()
{
	char str[50];
	/*ft_striteri
	 */

	printf("Test de ft_strmapi :\n");
	ft_strlcpy(str, "ABC",4);
	printf("La funcion ft_striteri modifica cada caracter del str: %s \n",str );
	ft_striteri(str,ft_test_iteri);
	printf("quedando: %s \n",str );
	printf("\n");
}