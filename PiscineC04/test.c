#include <stdio.h>
#include <stdlib.h>
#include "C04.h"
int	main(void)
{
	char 	base[5] = "01234";
	char 	str[20] = "ervpgmtkjl";
	char	str1[20] = " -723488a8888567";
	int 	ret;
	int		val_ex04 = -123;
	int 	minumero =  -2147483648;
	int 	minumero2 =  235468;
	ret = ft_strlen (str);
	printf("ft_strlen salida debe ser 10. Resultado =%d\n",ret);
	
	printf("Resultado ex01;");
	ft_putstr (str);
	
	printf("\n");
	printf("Resultado ex02-A;");
	ft_putnbr(minumero);
	printf("\n");
	printf("Resultado ex02-B;");
	ft_putnbr(minumero2);

	printf("\n");
	printf("Resultado ex03; %s \n",str1);
	printf ("Función atoi C  %d\n", atoi(str1));
	printf ("Función atoi ejercicio  %d\n", ft_atoi(str1));

	printf("\n");
	printf("Resultado ex04 para; %d en la base %s \n", val_ex04, base);
	printf ("Conversion ");
	ft_putnbr_base(val_ex04, base);
	printf ("\n");
	printf ("Conversion con error se repite letra e en la base : ertyue \n");
	ft_putnbr_base(ret, "ertyue");
	printf ("Conversion con error caracter prohibido : e+rtyu \n");
	ft_putnbr_base(ret, "e+rtyu");
	
	char str2[5] = "123";
	char base2[11] = "01234";
	printf("\n");
	printf("La base es:%s ", base2);
	printf("El valor es:%s ", str2);
	ret = ft_atoi_base (str2, base2);
	printf("La equivalencia en decimal es %d",ret);
	printf("\n");
	return (0);
}