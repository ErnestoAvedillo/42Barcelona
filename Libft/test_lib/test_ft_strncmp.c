#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strncmp ()
{
	char str[50];
	char str2[50];

	/*ft_strncmp
	 */
	ft_strlcpy(str, "test esto@thyuun atraco",22);
	ft_strlcpy(str2, "test esto es un atrco",22);
	printf("test ft_strncmp\n");
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 9));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 9));
	ft_strlcpy(str2, "test estothyuun atraco",22);
	ft_strlcpy(str, "test esto es un atraco",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str2, "test esto ES n atraco",22);
	ft_strlcpy(str, "test esto es un atraco",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str2, "test esto ES n atraco",22);
	ft_strlcpy(str, "test esto",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str, "test\200",8);
	ft_strlcpy(str2, "test\0",6);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 6));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 6));
	printf("\n");
}