#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strchr()
{
	/*ft_strchr
	 */
	char	var1 = 'r';
	char	var2 = 'R';
	char	var3 = '\0';
	char	str[50]; 
	printf("%sTest de ft_strchr%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "esto es un atraco",17);
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var1, ft_strchr(str, var1));
	printf("   strchr en -%s- al buscar -%c- retorna %p\n", str, var1, strchr(str, var1));
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var2, ft_strchr(str, var2));
	printf("   strchr en -%s- al buscar -%c- retorna %p\n", str, var2, strchr(str, var2));
	printf("%sTest4%s\n",KYEL, KNRM);
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var3, ft_strchr(str, var3));
	printf("   strchr en -%s- al buscar -%c- retorna %p\n", str, var3, strchr(str, var3));
	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
 	char *d1 = strchr(src, '\0');
 	char *d2 = ft_strchr(src, '\0');
	printf("%sTest5%s\n",KYEL, KNRM);
	printf("ft_strchr en cadenas con cero %p \n", d2);
	printf("   strchr en cadenas con cero %p \n", d1);

	printf("\n");

}