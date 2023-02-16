
void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    int temp;

    i = 0;
    while(i < size - 1)
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = temp;
            i = 0;
        }
        else
            i++;
    }
    return;
}
/*
#include<stdio.h>
int main(void)
{
    int i[10]={21,0, 4, 99, 6, 1, 3, 5, 6, 2};
    int j;
    
    j = -1;
    while (++j < 10)
        printf("%i\n", i[j]);
    sort_int_tab(i,10);
    j = -1;
    while (++j < 10)
        printf("%i\n", i[j]);
    return (0);

}
*/