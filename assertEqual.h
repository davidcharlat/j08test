#ifndef __ASSERTEQUAL_H__
#define __ASSERTEQUAL_H__
# include <stdio.h>

void    assertStringEqual(char *expected, char *received)
{
   int cursor;

	cursor = 0;
	while (*(expected + cursor) != '\0' && *(expected + cursor) == *(received + cursor))
			cursor++;
	if (*(expected + cursor) != *(received + cursor))
	{
	        fprintf(stderr, "STRING_NOT_EQUAL : expecting \"%s\" - received \"%s\".\n", expected, received);
	        exit(1);
	}
}

void    assertPtrEqual(void* expected, void* received)
{
    if (expected != received)
    {
        fprintf(stderr,"PTR_NOT_EQUAL : expecting %p - received %p.\n", expected, received);;
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
        fprintf(stderr, "INTEGER_EQUAL : received %d.\n", received);
        exit(1);
    }
}

void    assertCharEqual(char expected, char received)
{
    if (expected != received)
    {
        fprintf(stderr, "CHAR_NOT_EQUAL : expecting %c - received %c.\n", expected, received);
        exit(1);
    }
}

#endif
