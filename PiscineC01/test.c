#include <unistd.h>
#include <stdio.h>
#include "C01.h"

int main(void)
{
	int val;
	int *val2;
	int **val3;
	int ***val4;
	int ****val5;
	int *****val6;
	int ******val7;
	int *******val8;
	int ********val9;
	int *********val10;
	int a;
	int b;
	int div;
	int mod;
	char str[10] = "wertfdd";
	int matval [9] = {1,2,3,4,5,6,7,8,9};

	val = 234;
	printf("Antes era %d\n",val );
	ft_ft(&val);
	printf("Ahora es %d\n",val );

	val = 234;
	val2 = &val;
	val3 = &val2 ;
	val4 = &val3 ;
	val5 = &val4 ;
	val6 = &val5 ;
	val7 = &val6 ;
	val8 = &val7 ;
	val9 = &val8 ;
	val10 = &val9 ;

	printf("Antes era %d\n", *********val10 );
	printf("Antes era %d\n", val );
	ft_ultimate_ft(val10);
	printf("Ahora es %d\n",*********val10 );
	printf("Antes era %d\n", val);

	a=3;
	b=20;
	printf("a= %d;  b= %d\n", a, b);
	ft_swap (&a , &b);
	printf("a= %d;  b= %d\n", a, b);

	ft_div_mod (a, b, &div, &mod);
	printf("div= %d;  mod= %d\n", div, mod);

	ft_ultimate_div_mod (&a, &b);
	printf("a= %d;  b= %d\n", a, b);

	ft_putstr(str);
	printf("\n%s\n", str );
	printf("imprimiendo longitud str %d\n", ft_strlen(str) );

	printf("Matriz original\n");
	a = 0;
	while (a < 9)
	{
		printf("%d", matval[a] );
		a++;
	}
	printf("\n");
	ft_rev_int_tab(matval, 9);
	printf("Matriz invertida\n");
	a = 0;
	while (a < 9)
	{
		printf("%d", matval[a] );
		a++;
	}
	printf("\n");
	return (0);
}
