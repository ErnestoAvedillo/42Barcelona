#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strlcpy()
{
	/*ft_strlcpy
	 */
	char str[50] ="esto es un atraco asqueroso";
	printf("test ft_strlcpy\n");
	printf("La cadena era %s\n",str);
//	strlcpy (str, "pepito grillo", 10);	
	printf("La cadena con strlcpy es %s\n",str);
	ft_strlcpy(str, "pepito grillo", 10);
	printf("La cadena con mi ft_strlcpy es %s\n\n",str);

}