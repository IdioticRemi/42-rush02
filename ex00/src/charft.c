#include <rush02.h>

t_bool	ft_isnbr(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool	ft_ischar(char c, char comp)
{
	return (c == comp);
}

t_bool	ft_charinset(char c, t_str charset)
{
	int	j;

	j = -1;
	while (charset[++j])
		if (ft_ischar(c, charset[j]))
			return (TRUE);
	return (FALSE);
}
