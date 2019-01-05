
#include <stdio.h>

#include "other.h"

int main()
{
	printf("Hello world: %d :getNumber:%d\n", TEST_HEADER, getNumber());
	int a = 0;
	scanf("%d", a);
	return 0;
}