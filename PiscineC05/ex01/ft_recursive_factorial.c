int ft_recursive_factorial(int nb)
{
	int ret;

	ret = 1;
	if (nb > 1)
		ret *= nb * ft_recursive_factorial(nb-1);
	return (ret);
}
