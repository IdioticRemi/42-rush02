#include <rush02.h>

t_str	ft_getdict(t_rush rush, t_str key)
{
	t_dict	*dic;

	dic = rush.dict;
	while (dic->text[0] && ft_strcmp(dic->number, key))
		dic++;
	return dic->text;
}