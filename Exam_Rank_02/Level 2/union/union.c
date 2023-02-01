#include<unistd.h>
int main (int av, char **ac)
{
	int i;
	int j;
	int k;
	int l;
	int found;

	if (av == 3)
	{
		k = 0;
		while(++k <= 2)
		{
			i = 0;
			while (ac[k][i])
			{
				found = 0;
				l = 1;
				while (l <= k)
				{
					j = 0;
					if(l < k)
						while (ac[l][j])
						{
							if (ac[k][i] == ac[l][j])
								found = 1;
							j++;
						}
					else
						while (j < i)
						{
							if (ac[k][i] == ac[l][j])
								found = 1;
							j++;
						}
					l++;
				}
				if (!found)
					write(1, &ac[k][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}