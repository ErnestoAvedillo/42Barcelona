#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_memcmp ()
{
	char str[50];
	char str2[50];

	/*ft_memcmp
	 */
	printf("%stest de ft_memcmp%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "test esto @thyuun atraco",20);
	ft_strlcpy(str2, "test esto es un atrco",20);
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, ft_memcmp(str, str2, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, memcmp(str, str2, 20));
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, ft_memcmp(str2, str, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, memcmp(str2, str, 20));
	ft_strlcpy(str, "test esto@thyuun atraco",22);
	ft_strlcpy(str2, "test esto es un atrco",22);
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, ft_memcmp(str, str2, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str, str2, memcmp(str, str2, 20));
	printf("%sTest4%s\n",KYEL, KNRM);
	printf("ft_memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, ft_memcmp(str2, str, 20));
	printf("   memcmp compara el str -%s- con -%s- retorna %d\n", str2, str, memcmp(str2, str, 20));

}