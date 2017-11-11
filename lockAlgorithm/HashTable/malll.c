#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include<unistd.h>

int main()
{
	int *a;
	a = (int *)malloc(sizeof(int));
	*a = 10;
	printf("%d\n",*a);
	return 0;
}
