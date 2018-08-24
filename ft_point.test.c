#include "j08/ex03/ft_point.h"
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

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int		main(void)
{
	t_point	point;
		
	set_point(&point);
	
	printf("verifying point.x\n");
	assertIntEqual(42, point.x);
	printf("OK\n");
	printf("verifying point.y\n");
	assertIntEqual(21, point.y);
	printf("OK\n");
	return (0);
}
