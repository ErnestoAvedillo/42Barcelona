#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_atoi ()
{
	/*ft_atoi
	 */
 
	char	valor1[10];
	char	valor2[10];
	char	valor3[10];
	char	valor4[10];
	printf("test ft_atoi\n");
	ft_strlcpy(valor1, "fdr1234666",10);
	ft_strlcpy(valor2, "-4345A55",10);
//	printf("ft_atoi convierte el str -%s- en un entero y retorna \n", valor1 );
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor2, ft_atoi(valor2));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor2, atoi(valor2));
	ft_strlcpy(valor3, " 1234 666",10);
	ft_strlcpy(valor4, "- -4333555",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor3, ft_atoi(valor3));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor3, atoi(valor3));
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor4, ft_atoi(valor4));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor4, atoi(valor4));
	printf("\n");

}