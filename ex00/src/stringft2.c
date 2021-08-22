/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:16:52 by tschlege          #+#    #+#             */
/*   Updated: 2021/08/22 17:16:55 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

t_bool	ft_strcmp(t_str s1, t_str s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_bool	ft_stronlyhas(t_str str, t_str charset)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_charinset(str[i], charset))
			return (TRUE);
	return (FALSE);
}

t_str	ft_strscat(t_str src, t_str dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (j != 0)
	{
		dest[i + j] = ' ';
		dest[i + j + 1] = '\0';
	}
	else
		dest[i + j] = '\0';
	return (dest);
}
