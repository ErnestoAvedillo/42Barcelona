#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_atoi ()
{
	/*ft_atoi
	 */
 
	char	valor1[10];
	printf("%stest ft_atoi%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "fdr1234666",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest2%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "546:5",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest3%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "+548",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest4%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "054854",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest5%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "\e000074",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest6%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "+47+5",10);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest7%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "2147483647",25);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest8%s\n",KYEL, KNRM);
/*	ft_strlcpy(valor1, "\t\n\r\v\f  469 \n",25);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest9%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "\n\n\n  -46\b9 \n5d6",25);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1 , ft_atoi(valor1));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest10%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "      ++2344",25);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1 , ft_atoi(valor1));
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest11%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "-2147483648",12);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
	printf("%sTest12%s\n",KYEL, KNRM);
	ft_strlcpy(valor1, "\t\n\r\v\fd469 \n",18);
	printf("ft_atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, ft_atoi(valor1) );
	printf("   atoi convierte el str -%s- en un entero y retorna -%d- \n", valor1, atoi(valor1));
*/
	printf("fin\n");

	return;
}