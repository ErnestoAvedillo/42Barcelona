int ft_recursive_power(int nb, int power)
{
	int ret;

	ret = 1;
	if (power > 0)
	{
		ret *= nb * ft_recursive_power(nb, power - 1);
	}
	return (ret);
}
