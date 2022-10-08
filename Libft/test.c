#include "./entrega/libft.h"
#include "./test_lib/test_lib.h"
#include "test.h"

int is_func(char **ac, char *str)
{
	int i = 0;

	while (ac[i])
	{
		if (ft_strncmp(ac[i], str, ft_strlen(str)) == 0)
			return (1);
		i++;
	}
	return (0);
}

int main (int av, char **ac)
{
	if (av == 1 || is_func(ac,"isalpha"))
		test_ft_isalpha();
	if (av == 1 || is_func(ac,"isalnum"))
		test_ft_isalnum();
	if (av == 1 || is_func(ac,"isdigit"))
		test_ft_isdigit();
	if (av == 1 || is_func(ac,"isascii"))
		test_ft_isascii();
	if (av == 1 || is_func(ac,"isprint"))
		test_ft_isprint();
	if (av == 1 || is_func(ac,"strlen"))
		test_ft_strlen();
	if (av == 1 || is_func(ac,"memset"))
		test_ft_memset();
	if (av == 1 || is_func(ac,"strlcpy"))
		test_ft_strlcpy();
	if (av == 1 || is_func(ac,"strlcat"))
		test_ft_strlcat();
	if (av == 1 || is_func(ac,"bzero"))
		test_ft_bzero();
	if (av == 1 || is_func(ac,"memmove"))
		test_ft_memmove();
	if (av == 1 || is_func(ac,"memcpy"))
		test_ft_memcpy();
	if (av == 1 || is_func(ac,"toupper"))
		test_ft_toupper();
	if (av == 1 || is_func(ac,"tolower"))
		test_ft_tolower();
	if (av == 1 || is_func(ac,"strchr"))
		test_ft_strchr();
	if (av == 1 || is_func(ac,"strrchr"))
		test_ft_strrchr();
	if (av == 1 || is_func(ac,"strncmp"))
		test_ft_strncmp();
	if (av == 1 || is_func(ac,"memchr"))
		test_ft_memchr();
	if (av == 1 || is_func(ac,"memcmp"))
		test_ft_memcmp();
	if (av == 1 || is_func(ac,"strnstr"))
		test_ft_strnstr();
	if (av == 1 || is_func(ac,"atoi"))
		test_ft_atoi();
	if (av == 1 || is_func(ac,"calloc"))
		test_ft_calloc();
	if (av == 1 || is_func(ac,"strdup"))
		test_ft_strdup();
	if (av == 1 || is_func(ac,"substr"))
		test_ft_substr();
	if (av == 1 || is_func(ac,"strjoin"))
		test_ft_strjoin();
	if (av == 1 || is_func(ac,"strtrim"))
		test_ft_strtrim();
	if (av == 1 || is_func(ac,"split"))
		test_ft_split();
	if (av == 1 || is_func(ac,"itoa"))
		test_ft_itoa();
	if (av == 1 || is_func(ac,"strmapi"))
		test_ft_strmapi();
	if (av == 1 || is_func(ac,"striteri"))
		test_ft_striteri();
	if (av == 1 || is_func(ac,"putchar_fd"))
		test_ft_putchar_fd();
	if (av == 1 || is_func(ac,"putstr_fd"))
		test_ft_putstr_fd();
	if (av == 1 || is_func(ac,"putendl_fd"))
		test_ft_putendl_fd();
	if (av == 1 || is_func(ac,"putnbr_fd"))
		test_ft_putnbr_fd();
	if (av == 1 || is_func(ac,"bonus"))
		test_ft_bonus();
	printf("Goodby\n");
}