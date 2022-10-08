#include "../entrega/libft.h"
#include "test_lib.h"

void test_ft_calloc ()
{
	void *ptr1;
	void *ptr2;

	printf("%stest ft_calloc%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ptr1 = calloc(0,10);
	printf("con    calloc %p\n",ptr1 );
	free(ptr1);
	ptr2 = ft_calloc(0,10);
	printf("con ft_calloc %p\n",ptr2 );
	free(ptr2);
	printf("%sTest2%s\n",KYEL, KNRM);
	ptr1 = calloc(10,0);
	printf("con    calloc %p\n",ptr1 );
	free(ptr1);
	ptr2 = ft_calloc(10,0);
	printf("con ft_calloc %p\n",ptr2 );
	free(ptr2);
	printf("%sTest3%s\n",KYEL, KNRM);
	ptr1 = calloc(10,sizeof(long));
	printf("con    calloc %p\n",ptr1 );
	free(ptr1);
	ptr2 = ft_calloc(10,sizeof(long));
	printf("con ft_calloc %p\n",ptr2 );
	free(ptr2);

	printf("\n");
}