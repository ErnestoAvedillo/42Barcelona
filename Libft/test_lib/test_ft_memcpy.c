#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_memcpy()
{
	char str[50];
	char str2[50];	

	/*ft_memcpy
	 */
	printf("test ft_memcpy\n");
	ft_strlcpy(str2, "La prueba de memcpy",24);
	ft_strlcpy(str, "esto es un atraco",17);
	printf("antes de memcpy dst vale : %s\n", str);
	printf("antes de memcpy src vale : %s\n", str2);
	memcpy(str,str2,20);
	printf("despues de memcpy dst vale : %s\n", str);
	printf("despues de memcpy src vale : %s\n", str2);
	ft_strlcpy(str, "esto es un atraco",17);
	ft_strlcpy(str2, "La prueba de memcpy",24);
	
	printf("antes de ft_memcpy dst  vale: %s\n", str);
	printf("antes de ft_memcpy src  vale: %s\n", str2);
	ft_memcpy(str,str2,20);
	printf("despues de ft_memcpy dst  vale: %s\n", str);
	printf("despues de ft_memcpy src  vale: %s\n\n", str2);
}