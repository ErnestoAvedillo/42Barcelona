#include "../Libft/libft.h"
#include "test_lib.h"

void test_ft_strchr()
{
	/*ft_strchr
	 */
	char	var1 = 'r';
	char	var2 = 'R';
	char	var3 = '\0';
	char	str[50]; 
	printf("test ft_strchr\n");
	ft_strlcpy(str, "esto es un atraco",17);
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var1, ft_strchr(str, var1));
	printf("strchr en -%s- al buscar -%c- retorna %p\n", str, var1, strchr(str, var1));
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var2, ft_strchr(str, var2));
	printf("strchr en -%s- al buscar -%c- retorna %p\n", str, var2, strchr(str, var2));
	printf("ft_strchr en -%s- al buscar -%c- retorna %p\n", str, var3, ft_strchr(str, var3));
	printf("strchr en -%s- al buscar -%c- retorna %p\n", str, var3, strchr(str, var3));
	printf("strrchr en -%s- al buscar -%c- retorna %p\n", str, var3, strrchr(str, var3));
	printf("\n");

}