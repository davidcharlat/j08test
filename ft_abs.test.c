#include "j08/ex02/ft_abs.h"
#include <stdio.h>
#include <stdlib.h>

void    assertIntEqual(int expected, int received)
{
    if (expected != received)
    {
        fprintf(stderr, "INTEGER_NOT_EQUAL : expecting %d - received %d.\n", expected, received);
        exit(1);
    }
}

int main()
{
	printf ("ABS(-4) must return 4\n");
	assertIntEqual (4, ABS(-4));
	printf("OK\n");
	printf ("ABS(3) must return 3\n");
	assertIntEqual (3, ABS(3));
	printf("OK\n");
	return 0;
}
