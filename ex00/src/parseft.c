#include <rush02.h>

t_str	ft_strnindex(t_str str, int j, char c)
{
	int i;

	i = 0;
	while (*str && i < j)
	{
		if (ft_ischar(*str, c))
			i++;
		str++;
	}
	return (str);
}

t_dict	ft_parseline(t_str	str)
{
	t_dict	dict;

	dict.number = malloc(ft_strlenuntil(str, " :") + 1);
	if (!dict.number)
		return (dict);
	dict.number[0] = '\0';
	ft_strucat(dict.number, str, " :");
	while (ft_isnbr(*str))
		str++;
	while (ft_charinset(*str, " :"))
		str++;
	dict.text = malloc(ft_strlenuntil(str, "\n") + 1);
	if (!dict.text)
	{
		free(dict.number);
		return (dict);
	}
	dict.text[0] = '\0';
	ft_strucat(dict.text, str, "\n");
	return dict;
}

t_rush	ft_dictparse(t_str	dictpath)
{
	t_str	str;
	t_rush	rush;
	t_uint	i;

	rush.dictname = dictpath;
	rush.file = ft_fileread(dictpath);
	str = rush.file.content;
	rush.lines = ft_strcount(str, '\n') + 1;
	rush.dict = malloc((rush.lines + 1) * sizeof(t_dict));
	if (!rush.dict)
		return (rush);
	i = -1;
	while (++i < rush.lines)
		rush.dict[i] = ft_parseline(ft_strnindex(str, i, '\n'));
	rush.dict[i] = ft_parseline(":");
	return (rush);
}