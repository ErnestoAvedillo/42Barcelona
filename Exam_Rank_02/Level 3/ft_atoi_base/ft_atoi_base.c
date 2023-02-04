char *strcpy_base(char *dst, char *src)
{
	int i;

	i = -1;
	while (src[++i])
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (dst);
}

int char_pos(char c)
{
	int	i;
	char base[17];

	strcpy_base(base, "0123456789abcdef");
	i = 0;
	if (c>='A' && c <= 'F')
		c = c - 32;
	while (base[i] && base[i] != c)
		i++;
	return (i + 1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int signo;
	int val;
	int i;

	i = 0;
	signo = 1;
	if (str[0] == '-')
	{
		signo = -1;
		i++;
	}
	val = 0;
	while (str[i])
	{
		val = val * str_base + char_pos(str[i]) - 1;
		i++;
	}
	return (val * signo);
}
