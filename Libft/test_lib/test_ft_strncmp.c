#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strncmp ()
{
	char str[50];
	char str2[50];

	/*ft_strncmp
	 */
	printf("%sTest de ft_strncmp%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "test esto@thyuun atraco",22);
	ft_strlcpy(str2, "test esto es un atrco",22);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 9));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 9));
	ft_strlcpy(str2, "test estothyuun atraco",22);
	ft_strlcpy(str, "test esto es un atraco",22);
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str2, "test esto ES n atraco",22);
	ft_strlcpy(str, "test esto es un atraco",22);
	printf("%sTest4%s\n",KYEL, KNRM);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str2, "test esto ES n atraco",22);
	ft_strlcpy(str, "test esto",22);
	printf("%sTest5%s\n",KYEL, KNRM);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 20));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 20));
	ft_strlcpy(str, "test\200",8);
	ft_strlcpy(str2, "test\0",6);
	printf("%sTest6%s\n",KYEL, KNRM);
	printf("ft_strncmp compara -%s- con -%s- retorna %d\n", str, str2, ft_strncmp(str, str2, 6));
	printf("   strncmp compara -%s- con -%s- retorna %d\n", str, str2, strncmp(str, str2, 6));
	printf("%sTest7%s\n",KYEL, KNRM);
 	char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
 	char *s2 = "\x12\x02";
 	size_t size = 6;
 	int i1 = ((strncmp(s1, s2, size) > 0) ? 1 : ((strncmp(s1, s2, size) < 0) ? -1 : 0));
 	int i2 = ((ft_strncmp(s1, s2, size) > 0) ? 1 : ((ft_strncmp(s1, s2, size) < 0) ? -1 : 0));
 
 	if (i1 == i2)
 		printf("test success i1 =%d i2 = %d", i1, i2);
	else
	 	printf("Test failed i1 =%d i2 = %d", i1, i2);
	printf("\n");
}