#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_itoa ()
{
	char	*ptr;
	int		var1;;
	/*ft_itoa
	*/

	printf("%stest ft_itoa%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	var1 = 14567;
	ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str >%s< en el puntero %p\n", var1, ptr, ptr);
	free(ptr);
	printf("%sTest2%s\n",KYEL, KNRM);
	var1 = -4567;
	ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str >%s< en el puntero %p\n", var1, ptr, ptr);
	printf("\n");
	printf("%sTest3%s\n",KYEL, KNRM);
	free(ptr);
	ptr = ft_itoa(-2147483648LL);
	printf("el resultado de realizar la funcion con -2147483648LL  es %s\n",ptr);
	free(ptr);
	printf("%sTest4%s\n",KYEL, KNRM);
    ptr = ft_itoa(2147483647);
	printf("el resultado de realizar la funcion con 2147483647 es %s\n",ptr);
	free(ptr);
	printf("%sTest5%s\n",KYEL, KNRM);
    ptr = ft_itoa(0);
	printf("el resultado de realizar la funcion con 0 es %s\n",ptr);
	free(ptr);
	printf("%sTest6%s\n",KYEL, KNRM);
	var1 = rand();
    ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str >%s< en el puntero %p\n", var1, ptr, ptr);
	free(ptr);
	var1 = -9;
    ptr = ft_itoa(var1);
	printf("ft_itoa convierte el entero %d en el str >%s< en el puntero %p\n", var1, ptr, ptr);
	free(ptr);

}