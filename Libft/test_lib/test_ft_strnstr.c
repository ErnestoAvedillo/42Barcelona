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

    printf("ft_strnstr busca el str -%s- dentro de -%s- retorna respecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 3333333333333));
//	printf("   strnstr busca el str -%s- dentro de -%s- retorna respecto del inicio %p %p\n", str, str2, str2,    strnstr(str2, str, 3333333333333));
    printf("%sTest2%s\n",KYEL, KNRM);
	ft_strlcpy(str, "",20);
    printf("ft_strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 20));
//	printf("   strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2,    strnstr(str2, str, 20));
    printf("%sTest3%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "lorem ipsum dolor sit amet",27);
    ft_strlcpy(str, "",1);
    ft_strnstr(str2, str, 10);
    printf("ft_strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 20));
//    printf("   strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2,    strnstr(str2, str, 20));
    printf("%sTest4%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "lorem ipsum dolor sit amet",27);
    ft_strlcpy(str, "dolor",1);
    ft_strnstr(str2, str, 15);
    printf("ft_strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 15));
 //   printf("   strnstr busca el str -%s- dentro de -%s- retornarespecto del inicio %p %p\n", str, str2, str2,    strnstr(str2, str, 15));
    printf("%sTest5%s\n",KYEL, KNRM);
    char *s1 = "AAAAAAAAAAAAA";
    size_t max = strlen(s1);
 //   char *i1 = strnstr(s1, s1, max);
    char *i2 = ft_strnstr(s1, s1, max);
    printf("ft_strnstr busca el str -%s- dentro de -%s- en %zu retorna respecto del inicio %p %p\n", s1, s1, max, s1, i2);
//    printf("   strnstr busca el str -%s- dentro de -%s- en %zu retorna respecto del inicio %p %p\n", s1, s1, max, s1, i1);
    printf("%sTest6%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "",2);
    ft_strlcpy(str, "teste",6);
    printf("ft_strnstr busca el str -%s- dentro de -%s- en max 2 retorna respecto del inicio %p %p\n", str, str2, str2, ft_strnstr(str2, str, 2));
//    printf("   strnstr busca el str -%s- dentro de -%s- en max 2 retorna respecto del inicio %p %p\n", str, str2, str2,    strnstr(str2, str, 2));
    printf("%sTest7%s\n",KYEL, KNRM);
    char str3[] = "aaabcabcd";
    char str4[] = "aabc";
//    i1 = strnstr(str3, str4, 5);
    i2 = ft_strnstr(str3, str4, 5);
    max = 5;
    printf("ft_strnstr busca el str -%s- dentro de -%s- en max %zu retorna respecto del inicio %p %p\n",str4, str3,max, str3, i2);
//    printf("   strnstr busca el str -%s- dentro de -%s- en max %zu retorna respecto del inicio %p %p\n",str4, str3,max, str3, i1);
    printf("%sTest8%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "",2);
    ft_strlcpy(str, "teste",6);
    max = -1;
    printf("ft_strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2, ft_strnstr(str2, str, max));
//    printf("   strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2,    strnstr(str2, str, max));
    printf("%sTest9%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "",2);
    ft_strlcpy(str, "",2);
    max = -1;
    printf("ft_strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2, ft_strnstr(str2, str, max));
 //   printf("   strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2,    strnstr(str2, str, max));
    printf("%sTest10%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "aaabcabcd",10);
    ft_strlcpy(str, "aabc",6);
    max = -1;
    printf("ft_strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2, ft_strnstr(str2, str, max));
 //   printf("   strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2,    strnstr(str2, str, max));
    printf("%sTest11%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "aaabcabcd",10);
    ft_strlcpy(str, "a",2);
    max = -1;
    printf("ft_strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2, ft_strnstr(str2, str, max));
//    printf("   strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2,    strnstr(str2, str, max));
    printf("%sTest12%s\n",KYEL, KNRM);
    ft_strlcpy(str2, "aaabcabcd",10);
    ft_strlcpy(str, "c",2);
    max = -1;
    printf("ft_strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2, ft_strnstr(str2, str, max));
//    printf("   strnstr busca el str -%s- dentro de -%s- max %zu retorna respecto del inicio %p %p\n", str, str2, max, str2,    strnstr(str2, str, max));

    printf("\n");
}