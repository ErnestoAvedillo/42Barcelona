#include<stddef.h>
size_t ft_strspn(const char *s, const char *accept)
{
	size_t i;
	int j;

	j = 0;
	i = 0;
	while (s[i])
		{
			if (!accept[j])
				j = 0;
			if (accept[j] == s[i])
			{
				i++;
				j++;
			}
			else
				return (i);
		}
	return(i);
}
