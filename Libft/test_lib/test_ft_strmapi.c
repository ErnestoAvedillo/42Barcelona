#include "../entrega/libft.h"
#include "test_lib.h"

char	ft_test_mapi(unsigned int i, char c)
{
	i += 1;
	return (c - 32);
}

void test_ft_strmapi ()
{
	/*ft_strmapi
	 */
	printf("Test de ft_strmapi :\n");
	printf("ABC : %s\n", ft_strmapi("abc", ft_test_mapi));
	printf("ABC : %s\n", ft_strmapi("idf", ft_test_mapi));
	printf("\n");

}