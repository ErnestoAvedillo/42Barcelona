int ft_iterative_factorial(int nb)
{
	int ret;

	ret = 1;
	while (nb > 1)
	{
		ret *= nb;
		nb--;
	}
	return ret;
}
