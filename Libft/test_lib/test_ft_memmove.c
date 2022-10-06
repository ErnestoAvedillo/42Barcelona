#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_memmove()
{
	char str[50];
	char str2[50];
	
	/*ft_memmove
	 */
	printf("%stest de ft_memmove%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str2, "La prueba de ft_memmove",25);
	ft_strlcpy(str, "esto es un atraco",17);
	printf("antes de memmove dst vale : %s\n", str);
	printf("antes de memmove src vale : %s\n", str2);
	memmove(str,str2,20);
	printf("despues de memmove dst vale : %s\n", str);
	printf("despues de memmove src vale : %s\n", str2);

	ft_strlcpy(str2, "La prueba de ft_memmove",25);
	ft_strlcpy(str, "esto es un atraco",17);
	
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("antes de ft_memmove dst  vale: %s\n", str);
	printf("antes de ft_memmove src  vale: %s\n", str2);
	ft_memmove(str,str2,20);
	printf("despues de ft_memmove dst  vale: %s\n", str);
	printf("despues de ft_memmove src  vale: %s\n\n", str2);
}
