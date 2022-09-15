#include <unistd.h>

int main(int av, char **ac)
{
	int count;
	int count2;

	if (av < 2)
		return (0);
	count = av-1;
	while (count > 0)
	{
		count2 = 0;
		while (ac[count][count2] != '\0')
		{
			write (1, &ac[count][count2], 1);
			count2++;
		}
		write(1, "\n", 1);
		count--;
	}
}