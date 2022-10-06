#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_memcpy()
{
	char str[50];
	char str2[50];	
//	void *ptr;
	/*ft_memcpy
	 */
	printf("%stest de ft_memcpy%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str2, "La prueba de memcpy",24);
	ft_strlcpy(str, "esto es un atraco",17);
	printf("antes de memcpy dst vale : %s\n", str);
	printf("antes de memcpy src vale : %s\n", str2);
	printf("%sTest2%s\n",KYEL, KNRM);
	memcpy(str,str2,20);
	printf("despues de memcpy dst vale : %s\n", str);
	printf("despues de memcpy src vale : %s\n", str2);
	ft_strlcpy(str, "esto es un atraco",17);
	ft_strlcpy(str2, "La prueba de memcpy",24);
	printf("%sTest3%s\n",KYEL, KNRM);
	printf("antes de ft_memcpy dst  vale: %s\n", str);
	printf("antes de ft_memcpy src  vale: %s\n", str2);
	printf("%sTest4%s\n",KYEL, KNRM);
	ft_memcpy(str,str2,20);
	printf("despues de ft_memcpy dst  vale: %s\n", str);
	printf("despues de ft_memcpy src  vale: %s\n\n", str2);
/*	ptr = memcpy(((void *)0), ((void *)0), 3);
	printf ("   memcpy(((void *)0), ((void *)0), 3) retorna %p", ptr);
	ptr = ft_memcpy(((void *)0), ((void *)0), 3);
	printf ("ft_memcpy(((void *)0), ((void *)0), 3) retorna %p", ptr);
*/
}