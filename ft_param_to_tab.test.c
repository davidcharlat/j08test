#include "j08/ex04/ft_stock_par.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_split_whitespaces.c"
#include "assertEqual.h"

struct s_stock_par	*ft_param_to_tab(int ac, char **av);

int     main(int argc, char **argv)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	
	t_stock_par *structab;
	
	structab = ft_param_to_tab(argc, argv);

	printf ("testing ./test 1st arg2 \"3rd argument\"\n");
	printf (" the size of the 1st arg is 3\n");
	assertIntEqual (3, structab[1].size_param);
	printf("OK\n");
	printf (" the structure contains the address of arg nb1\n");
	assertStringEqual (argv[1], structab[1].str);
	printf("OK\n");
	printf (" the structure contains the address of arg nb0\n");
	assertStringEqual (argv[0], structab[0].str);
	printf("OK\n");
	printf (" the structure contains the address of the copy of arg nb1\n");
	assertStringEqual (argv[1], structab[1].copy);
	printf("OK\n");
	printf (" the structure contains the address of the copy of arg nb0\n");
	assertStringEqual (argv[0], structab[0].copy);
	printf("OK\n");
	printf ("words of arg3 are correctly taken into account\n");
	assertStringEqual ("3rd", (structab[3].tab)[0]);
	printf("1st word OK\n");
	assertStringEqual ("argument", (structab[3].tab)[1]);
	printf("2nd word OK\n");
	printf("the last shebang must contain NULL in its 'str' element\n");
	assertPtrEqual (NULL, structab[4].str);
	printf("OK\n");
	
	while (i <= 3)
	{
		free (structab[i].copy);
		while ((structab[i].tab)[j])
			free ((structab[i].tab)[j++]);
		free (structab[i].tab);
		i++;
	}
	free (structab);
	return (0);
}
