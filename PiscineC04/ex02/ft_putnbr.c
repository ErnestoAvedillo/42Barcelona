#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	val;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
		write(1, "-", 1);
	val = nb / 10;
	if (val > 0)
		ft_putnbr(val);
	val = nb % 10 + '0';
	write(1, &val, 1);

}