#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_putnbr_fd ()
{
	/*ft_putnbr_fd
	 */
	printf("%stest de ft_putnbr_fd%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_putnbr_fd(3234,1);
	ft_putchar_fd('\n',1);
	printf("%sTest2%s\n",KYEL, KNRM);
	ft_putnbr_fd(-987441,1);
	ft_putchar_fd('\n',1);
	printf("%sTest3%s\n",KYEL, KNRM);
	ft_putnbr_fd(0,1);
	ft_putchar_fd('\n',1);
	printf("%sTest4%s\n",KYEL, KNRM);
	ft_putnbr_fd(2,1);
	ft_putchar_fd('\n',1);
	printf("%sTest5%s\n",KYEL, KNRM);
	ft_putnbr_fd(-5,1);
	ft_putchar_fd('\n',1);
	printf("%sTest6%s\n",KYEL, KNRM);
	ft_putnbr_fd(-57,1);
	ft_putchar_fd('\n',1);
	printf("%sTest7%s\n",KYEL, KNRM);
	ft_putnbr_fd(-2147483648LL,1);
	ft_putchar_fd('\n',1);
	printf("%sTest8%s\n",KYEL, KNRM);
	ft_putnbr_fd(10000043,1);
	ft_putchar_fd('\n',1);
	printf("%sTest9%s\n",KYEL, KNRM);
	ft_putnbr_fd(-10000043,1);
	ft_putchar_fd('\n',1);

	printf("\n");
}
