#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "j08/ex05/ft_stock_par.h"
#include "ft_split_whitespaces.c"
#include "j08/ex04/ft_param_to_tab.c"

void	ft_show_tab(struct s_stock_par *par);
struct	s_stock_par	*ft_param_to_tab(int ac, char **av);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main (int ac, char **av)
{
	t_stock_par *structab;
	int i;
	int j;
	
	i = 0;
	structab = ft_param_to_tab(ac, av);
	ft_show_tab(structab);
	
	printf("files compiled: OK\n");
	j = 0;

	while (i < ac)
	{
		j = 0;
		free (structab[i].copy);
		while ((structab[i].tab)[j])
			free ((structab[i].tab)[j++]);
		free (structab[i].tab);
		i++;
	}
	free (structab);
	return(0);
}
