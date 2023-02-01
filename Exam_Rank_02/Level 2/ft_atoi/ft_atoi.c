int ft_isdigit(char c)
{
	if (c >= '0' && c<= '9')
		return (1);
	return (0);
}
int ft_atoi(const char *str)
{
	int i;
	int signo;
	int c;

	i = 0;
	signo = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
	{
		signo *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	c = 0;
	while (ft_isdigit(str[i]))
	{
		c = c * 10 + str[i] - '0';
		i++;
	}
	return (c * signo);
}
