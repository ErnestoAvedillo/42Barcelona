#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_strlcat()
{
	/*ft_strlcat
	 */
	int val; 
	printf("%sTest de ft_strlcat%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	char str[50] = "La prueba de ft_strlcat";
	char str2[50] = "esto es un atraco";

	size_t retval;
	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de strlcat dst vale : %s\n", str);
	printf("antes de strlcat src vale : %s\n", str2);
//	retval = strlcat(str,str2,16);
//	printf("despues de strlcat dst  vale: %s -- return value %u\n", str, retval);
//	printf("despues de strlcat src vale : %s\n", str2);


	ft_strlcpy(str, "rrrrrr",6);
	str2[11] = 'a';
	ft_strlcpy(str2, "lorem",18);
	printf("antes de ft_strlcat dst  vale: %s\n", str);
	printf("antes de ft_strlcat src  vale: %s\n", str2);
	val = 15;
	retval = ft_strlcat(str,str2,val);
	printf("despues de ft_strlcat con valor %d dst vale: %s -- return value %lu\n", val, str, retval);
	printf("despues de ft_strlcat src valor %d vale: %s\n\n", val, str2);
	
	printf("%sTest2%s\n",KYEL, KNRM);
	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de strlcat dst vale : %s\n", str);
	printf("antes de strlcat src vale : %s\n", str2);
//	val = 35;
//	retval = strlcat(str,str2,val);
//	printf("despues de strlcat dst  vale: %s -- return value %u\n", str, retval);
//	printf("despues de strlcat src vale : %s\n", str2);

	ft_strlcpy(str2, "La prueba de ft_strlcat",25);
	ft_strlcpy(str, "esto es un atraco",18);
	printf("antes de ft_strlcat dst  vale: %s\n", str);
	printf("antes de ft_strlcat src  vale: %s\n", str2);
	val = 35;
	retval = ft_strlcat(str,str2,35);
	printf("despues de ft_strlcat con valor %d  dst  vale: %s -- return value %lu\n", val, str, retval);
	printf("despues de ft_strlcat con valor %d  src  vale: %s\n\n",val ,str2);

	char dest1[30]; memset(dest1, 0, 30);
	char dest2[30]; memset(dest2, 0, 30);
	size_t val1 = ft_strlcat(dest1, "123", 0);
	size_t val2 = strlcat(dest2, "123", 0);
	printf("despues de ft_strlcat con valor %d  src  vale: %s -- retorna %zu \n",0 ,dest1, val1);
	printf("despues de    strlcat con valor %d  src  vale: %s -- retorna %zu \n",0 ,dest2, val2);

}
