#include <unistd.h>

int main(int av, char **ac)
{
	int count;

	count = av;
	count = 0;
	while (ac[0][count] != '\0')
	{
		write(1, &ac[0][count], 1);
		count++;
	}
}
