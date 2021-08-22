#include <rush02.h>

t_str ft_watisuite(t_str str)
{
	int	str_len;
	int zero_nb;
	t_str wati;

	wati = NULL;
	str_len = ft_strlen(str);
	zero_nb = str_len - 1;
	if (zero_nb >= 3)
		while (zero_nb % 3)
			zero_nb--;
	wati = malloc(zero_nb + 2);
	if(!wati)
		return (NULL);
	wati[zero_nb + 1] = '\0';
	while (zero_nb)
	{
		wati[zero_nb] = '0';
		zero_nb--;
	}
	wati[0] = '1';
	return (wati);
}

t_str ft_watireste(t_str str)
{
	int str_len;
	int nbr;
	int zero_nb;
	int	i;
	t_str wati;

	str_len = ft_strlen(str);
	zero_nb = str_len - 1;
	if (zero_nb >= 3)
		while (zero_nb % 3)
			zero_nb--;
	nbr = str_len - zero_nb;
	wati = malloc(nbr + 1);
	if (!wati)
		return (NULL);
	i = 0;
	while (i < nbr)
	{
		wati[i] = str[i];
		i++;
	}
	wati[nbr] = '\0';
	return (wati);
}

t_str ft_watidec(t_str str)
{
	t_str wati;

	wati = malloc(3);
	if(!wati)
		return (NULL);
	if (ft_charinset(str[0], "3456789"))
	{
		wati[0] = str[0];
		wati[1] = '0';
		wati[2] = '\0';
		return (wati);
	}
	wati[0] = '\0';
	return (wati);
}

t_str ft_watiunit(t_str str)
{
	t_str wati;
	int ln;

	ln = ft_strlen(str);
	wati = malloc(3);
	if (!wati)
		return (NULL);
	if (ft_charinset(str[ln - 2], "12"))
	{
		wati[0] = str[ln - 2];
		wati[1] = str[ln - 1];
		wati[2] = '\0';
		return (wati);
	}
	wati[0] = str[ln - 1];
	wati[1] = '\0';
	return (wati);
}

t_uint ft_watisum(t_rush rush, t_str s)
{
	t_uint l;

	l = 0;
	while (ft_strlen(ft_watisuite(s)) > 3)
	{
		if (ft_strlen(ft_watireste(s)) == 3)
		{
			l += ft_strlen(ft_getdict(rush, ft_watireste(ft_watireste(s)))) + 4;
			l += ft_strlen(ft_getdict(rush, ft_watisuite(ft_watireste(s))));
			l += ft_strlen(ft_getdict(rush, ft_watidec(ft_watireste(s + 1))));
			l += ft_strlen(ft_getdict(rush, ft_watiunit(ft_watireste(s + 1))));
		}
		l += ft_strlen(ft_getdict(rush, ft_watisuite(s))) + 1;
		s += 3;
	}
	if (ft_strlen(ft_watisuite(s)) == 3)
	{
		l += ft_strlen(ft_getdict(rush, ft_watireste(s))) + 2;
		l += ft_strlen(ft_getdict(rush, ft_watisuite(s)));
		s += 1;
	}
	l += ft_strlen(ft_getdict(rush, ft_watidec(s))) + 2;
	l += ft_strlen(ft_getdict(rush, ft_watiunit(s)));
	return (l);
}
