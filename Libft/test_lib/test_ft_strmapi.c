#include "../entrega/libft.h"
#include "test_lib.h"

char	ft_test_mapi(unsigned int i, char c)
{
	i += 1;
	if(c >= 65 && c <= 90 )
		return (c + 32);
	if(c >= 97 && c <= 122 )
		return (c - 32);
	return (c);
}

void test_ft_strmapi ()
{
	/*ft_strmapi
	 */
	printf("%sTest de ft_strmapi%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	printf("Test de ft_strmapi :\n");
	printf("Tengo GaNas : %s\n", ft_strmapi("Tengo GaNas", ft_test_mapi));
	printf("%sTest2%s\n",KYEL, KNRM);
	printf("TieNes Hambre? : %s\n", ft_strmapi("TieNes Hambre?", ft_test_mapi));
	printf("\n");

}