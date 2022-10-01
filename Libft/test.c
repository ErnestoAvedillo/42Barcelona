#include "./entrega/libft.h"
#include "./test_lib/test_lib.h"


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
	if (av == 1 || is_func(ac,"ft_isalpha"))
		test_ft_isalpha();
	if (av == 1 || is_func(ac,"ft_isalnum"))
		test_ft_isalnum();
	if (av == 1 || is_func(ac,"ft_isdigit"))
		test_ft_isdigit();
	if (av == 1 || is_func(ac,"ft_isascii"))
		test_ft_isascii();
	if (av == 1 || is_func(ac,"ft_isprint"))
		test_ft_isprint();
	if (av == 1 || is_func(ac,"ft_strlen"))
		test_ft_strlen();
	if (av == 1 || is_func(ac,"ft_memset"))
		test_ft_memset();
	if (av == 1 || is_func(ac,"ft_strlcpy"))
		test_ft_strlcpy();
	if (av == 1 || is_func(ac,"ft_strlcat"))
		test_ft_strlcat();
	if (av == 1 || is_func(ac,"ft_bzero"))
		test_ft_bzero();
	if (av == 1 || is_func(ac,"ft_memmove"))
		test_ft_memmove();
	if (av == 1 || is_func(ac,"ft_memcpy"))
		test_ft_memcpy();
	if (av == 1 || is_func(ac,"ft_toupper"))
		test_ft_toupper();
	if (av == 1 || is_func(ac,"ft_tolower"))
		test_ft_tolower();
	if (av == 1 || is_func(ac,"ft_strchr"))
		test_ft_strchr();
	if (av == 1 || is_func(ac,"ft_strrchr"))
		test_ft_strrchr();
	if (av == 1 || is_func(ac,"ft_strncmp"))
		test_ft_strncmp();
	if (av == 1 || is_func(ac,"ft_memchr"))
		test_ft_memchr();
	if (av == 1 || is_func(ac,"ft_memcmp"))
		test_ft_memcmp();
	if (av == 1 || is_func(ac,"ft_strnstr"))
		test_ft_strnstr();
	if (av == 1 || is_func(ac,"ft_atoi"))
		test_ft_atoi();
	if (av == 1 || is_func(ac,"ft_calloc"))
		test_ft_calloc();
	if (av == 1 || is_func(ac,"ft_strdup"))
		test_ft_strdup();
	if (av == 1 || is_func(ac,"ft_substr"))
		test_ft_substr();
	if (av == 1 || is_func(ac,"ft_strjoin"))
		test_ft_strjoin();
	if (av == 1 || is_func(ac,"ft_strtrim"))
		test_ft_strtrim();
	if (av == 1 || is_func(ac,"ft_split"))
		test_ft_split();
	if (av == 1 || is_func(ac,"ft_itoa"))
		test_ft_itoa();
	if (av == 1 || is_func(ac,"ft_strmapi"))
		test_ft_strmapi();
	if (av == 1 || is_func(ac,"ft_striteri"))
		test_ft_striteri();
	if (av == 1 || is_func(ac,"ft_putchar_fd"))
		test_ft_putchar_fd();
	if (av == 1 || is_func(ac,"ft_putstr_fd"))
		test_ft_putstr_fd();
	if (av == 1 || is_func(ac,"ft_putendl_fd"))
		test_ft_putendl_fd();
	if (av == 1 || is_func(ac,"ft_putnbr_fd"))
		test_ft_putnbr_fd();
	

}