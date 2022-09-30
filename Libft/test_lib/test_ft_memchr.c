#include "../Libft/libft.h"
#include "test_lib.h"

void test_ft_memchr ()
{
	char str[50];
	char str2[50];
	char var1 = 'r';
	/*ft_memchr
	 */
	ft_strlcpy(str, "test esto@thyuun atraco",22);
	ft_strlcpy(str2, "test esto es un atrco",22);

	printf("test ft_memchr\n");
	printf("ft_memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2, ft_memchr(str2, var1, 20));
	printf("   memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2,  memchr(str2, var1, 20));
	var1 = 'w';
	printf("ft_memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2, ft_memchr(str2, var1, 20));
	printf("   memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2,  memchr(str2, var1, 20));
	var1 = 'w';
	printf("ft_memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2, ft_memchr(str2, var1, 50));
	printf("   memchr busca el caracter -%c- en -%s- retorna %p\n", var1, str2,  memchr(str2, var1, 50));
}