#include "j08/ex00/ft.h"
#include <stdio.h>
#include <stdlib.h>

void    assertStringEqual(char *expected, char *received)
{
   int cursor;

	cursor = 0;
	while (*(expected + cursor) != '\0' && *(expected + cursor) == *(received + cursor))
			cursor++;
	if (*(expected + cursor) != *(received + cursor))
	{
	        fprintf(stderr, "STRING_NOT_EQUAL : expecting \n%s - received\n %s.\n", expected, received);
	        exit(1);
	}
}

void    assertIntEqual(int expected, int received)
{
    if (expected != received)
    {
        fprintf(stderr, "INTEGER_NOT_EQUAL : expecting %d - received %d.\n", expected, received);
        exit(1);
    }
}

void    assertIntnotEqual(int expected, int received)
{
    if (expected == received)
    {
        fprintf(stderr, "INTEGER_EQUAL : expecting not %d - received %d.\n", expected, received);
        exit(1);
    }
}

int     main(void)
{
	char str[] = "coucou\n";
	char str2[] = "hello";
	int a;
	int b;
	
	a = 4;
	b = 6;
	printf("testing ft_putchar\n");
	ft_putchar ('\n');
	printf("OK\n");
	printf("testing ft_putstr\n");
	ft_putstr (str);
	printf("OK\n");
	printf("testing ft_strcmp\n");
	assertIntEqual(ft_strcmp(str, str), 0);
	assertIntnotEqual(ft_strcmp(str, str2), 0);
	printf("OK\n");
	printf("testing ft_strlen\n");
	assertIntEqual(7, ft_strlen(str));
	printf("OK\n");
	printf("testing ft_swap\n");
	ft_swap(&a,&b);
	assertIntEqual(6, a);
	assertIntEqual(4, b);
	printf("OK\n");
	return (0);
}
