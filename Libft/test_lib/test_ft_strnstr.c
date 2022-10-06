#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strnstr ()
{
	char str[50];
	char str2[50];


	/*ft_strnstr
	 */
    printf("%sTest de ft_strstr%s\n",KGRN, KNRM);
    printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "es un",20);
	ft_strlcpy(str2, "test esto es un atrco",20);

	printf("ft_strnstr busca el str -%s- dentro de -%s- retorna respecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 20));
//	printf("   strnstr busca el str -%s- dentro de -%s- retorna %p\n", str, str2, strnstr(str2, str, 20));
    printf("%sTest2%s\n",KYEL, KNRM);
	ft_strlcpy(str, "",20);
	printf("ft_strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 20));
    printf("%sTest3%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "lorem ipsum dolor sit amet",27);
    ft_strlcpy(str, "",1);
    ft_strnstr(str2, str, 10);
    printf("ft_strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 20));
    printf("%sTest4%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "lorem ipsum dolor sit amet",27);
    ft_strlcpy(str, "dolor",1);
    ft_strnstr(str2, str, 15);
    printf("ft_strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 15));

    printf("\n");
}