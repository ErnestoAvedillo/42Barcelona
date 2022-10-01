#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strnstr ()
{
	char str[50];
	char str2[50];


	/*ft_strnstr
	 */
	ft_strlcpy(str, "es un",20);
	ft_strlcpy(str2, "test esto es un atrco",20);

	printf("test ft_strstr\n");
	printf("ft_strnstr busca el str -%s- dentro de -%s- retorna %p\n", str, str2, ft_strnstr(str2, str, 20));
//	printf("   strnstr busca el str -%s- dentro de -%s- retorna %p\n", str, str2, strnstr(str2, str, 20));
	ft_strlcpy(str, "",20);
	printf("ft_strnstr busca el str -%s- dentro de -%s- retorna %p\n", str, str2, ft_strnstr(str2, str, 20));

}