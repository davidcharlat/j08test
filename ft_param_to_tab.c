#include "ft_stock_par.h"
#include <stdlib.h>

char	**ft_split_whitespaces(char *str);

int ft_size_param(char **av, int rank)
{
	int	cursor;
	
	cursor = 0;
	while (av[rank][cursor])
		cursor++;
	return (cursor);
}

char	*ft_strdup(char *src)
{
	int		src_lenght;
	int		cursor;
	char	*new_str;
	
	src_lenght = 0;
	cursor = 0;
	while (src[src_lenght])
			src_lenght++;
	new_str = (char*)malloc(sizeof(*src) * (src_lenght + 1));
	cursor = 0;
	while (cursor <= src_lenght)
		new_str[cursor] = src[cursor++];
	return (new_str);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int i;
	t_stock_par *struct_ptt;
	i = 0;
	struct_ptt = (t_stock_par*)malloc(sizeof (t_stock_par) * (ac));
	while (i < ac)
	{
		struct_ptt[i].size_param = ft_size_param(av, i);
		struct_ptt[i].str = av[i];
		struct_ptt[i].copy = ft_strdup(av[i]);
		struct_ptt[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	struct_ptt[i].str = NULL;
	return (struct_ptt);
}
