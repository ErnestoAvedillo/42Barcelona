#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strrchr()
{
	/*ft_strrchr
	 */
	char 	var1 = 'a';
	char	var2 = 'R';
	char	var3 = '2';
	char	str[50];
	printf("%sTest de ft_strrchr%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "esto es un atraco", 17);
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("ft_strrchr en -%s- al buscar -%c- retorna %p\n", str, var1, ft_strrchr(str, var1));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var1, strrchr(str, var1));
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("ft_strrchr en -%s- al buscar -%c- retorna %p\n", str, var2, ft_strrchr(str, var2));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var2, strrchr(str, var2));
	printf("%sTest4%s\n",KYEL, KNRM);
	printf("ft_strrchr en -%s- al buscar -%c- retorna %p\n", str, var3, ft_strrchr(str, var3));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var3, strrchr(str, var3));
	var3 = ' ';
	ft_strlcpy(str, "lorem \n ipsum \t dolor \n sit \t amet",40);
	printf("%sTest5%s\n",KYEL, KNRM);
	printf("ft_strrchr en -%s- al buscar -%c- retorna %p\n", str, var3, ft_strrchr(str, var3));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var3, strrchr(str, var3));

	printf("\n");
}