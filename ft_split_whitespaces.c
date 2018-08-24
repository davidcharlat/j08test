#include <stdlib.h>

int		find_space(char *str, int pos)
{
	if ((str[pos] == '\n') || (str[pos] == '\t') || (str[pos] == ' '))
		return (1);
	return (0);
}

char	*copy_wd_till_space(char *str, int pos)
{
	char *new_wd;
	int wd_len;
	
	wd_len = 0;
	while ((str[wd_len + pos]) && (find_space(str, pos) == 0))
		wd_len++;
	new_wd = (char*)malloc(sizeof(char) * (wd_len + 1));
	wd_len = 0;
	while ((str[wd_len + pos]) 
			&& (find_space(str, wd_len + pos) == 0))
		new_wd[wd_len] = str[wd_len++ + pos];
	new_wd[wd_len] = '\0';
	return (new_wd);
}

int		is_new_wd(char *str, int cursor)
{
	int i;
	int test;
	
	i = 0;
	test = 1;
	while ((cursor - i >= 0) && (i < 1))
	{
		if (find_space(str, cursor-i))
			test = 0;
		i++;
	}
	if ((test == 1) && 
		(((cursor >= 1) && find_space(str, cursor - 1))
			 || (cursor == 0)))
		return (1);
	return (0);
}

int		count_wd(char *str)
{
	int cursor;
	int count;
	
	count = 0;
	cursor = 0;
	while (str[cursor])
	{
		if (is_new_wd(str, cursor++))
			count++;
	}
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	char **tab;
	int cursor;
	int count;
	
	count = 0;
	cursor = 0;
	tab = (char**)malloc(sizeof(char*) * (count_wd(str)) + 1);
	while (str[cursor])
	{
		if (is_new_wd(str, cursor))
			tab[count++] = copy_wd_till_space(str, cursor);
		cursor++;
	}
	tab[count] = 0;
	return (tab);
}
