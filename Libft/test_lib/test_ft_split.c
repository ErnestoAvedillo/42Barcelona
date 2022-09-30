#include "../Libft/libft.h"
#include "test_lib.h"

void test_ft_split ()
{
	/*ft_split
	*/
	char str[50];
	int	i = 0;
	char **str3;
	char div = 'c';
	printf("test ft_split\n");
	ft_strlcpy(str, "wwwcrrrctttyycoooppy",20);
	str3 = ft_split(str, div);
	while(str3[i])
	{
		printf("ft_split divide el str -%s- entre todos los caracteres -%c- y queda: -%s- en el puntero %p nr %d\n", str, div, str3[i], str3[i], i);
		i++;
	}
	printf("\n");
	free(str3);
}