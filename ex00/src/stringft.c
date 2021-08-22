#include <rush02.h>

t_uint	ft_strlen(t_str str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_uint	ft_strlenuntil(t_str str, t_str stop)
{
	int i;

	i = 0;
	while (str[i] && !ft_charinset(str[i], stop))
		i++;
	return (i);
}

t_bool	ft_strhas(t_str str, t_str charset)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_charinset(str[i], charset))
			return (TRUE);
	return (FALSE);
}

t_uint	ft_strcount(t_str str, char c)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_ischar(*str, c))
			i++;
		str++;
	}
	return (i);
}

t_str	ft_strucat(t_str dest, t_str src, t_str stop)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && !ft_charinset(src[j], stop))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
