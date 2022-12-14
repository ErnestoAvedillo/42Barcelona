#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_split ()
{
	/*ft_split
	*/
	char str[50];
	int	i = 0;
	int	j = 0;
	char **str3;
	char **str4;
	char div = 'c';
	printf("%sTest de ft_split%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "wwwcrrrctttyycoooppy",20);
	str3 = ft_split(str, div);
	while(str3[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str3[i], str3[i], i);
		i++;
	}
	printf("\n");
	free(str3);

	printf("%sTest2%s\n",KYEL, KNRM);
	ft_strlcpy(str, "wwwcccccrrrccccctttyycccccoooppy",32);
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest3%s\n",KYEL, KNRM);
	ft_strlcpy(str, "cccccwwwcccccrrrccccctttyycccccoooppyccccc",42);
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i] != NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest4%s\n",KYEL, KNRM);
	ft_strlcpy(str, "cccccccccccccccccccccccccccccccccc",34);
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest5%s\n",KYEL, KNRM);
	ft_strlcpy(str, "cccccwwwcccccrrrccccctttyycccccoooppyccccc",42);
	div = 'a';
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest6%s\n",KYEL, KNRM);
	ft_strlcpy(str, "      split       this for   me  !",35);
	div = ' ';
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest6%s\n",KYEL, KNRM);
	ft_strlcpy(str, "xxxxxxxxhello!",15);
	div = 'x';
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		j = 0;
		while (str4[i][j] != '\0')
			write(1,&str4[i][j++],1);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest7%s\n",KYEL, KNRM);
	ft_strlcpy(str, "      split       this for   me  !       ",42);
	div = ' ';
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest8%s\n",KYEL, KNRM);
	ft_strlcpy(str, "",1);
	div = 'z';
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest9%s\n",KYEL, KNRM);
	ft_strlcpy(str, "xxxxxxxxhello!",15);
	div = 'x';
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);

	printf("%sTest10%s\n",KYEL, KNRM);
	ft_strlcpy(str, "hello!",7);
	div = ' ';
	str4 = ft_split(str, div);
	i = 0;		
	while(str4[i]!= NULL)
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str4[i], str4[i], i);
		i++;
	}
	printf("\n");
	free(str4);



}