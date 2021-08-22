/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watift2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:22:08 by tschlege          #+#    #+#             */
/*   Updated: 2021/08/22 17:22:10 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

void	ft_waticat(t_rush rush, t_str d, t_str s)
{
	while (ft_strlen(ft_watisuite(s)) > 3)
	{
		if (ft_strlen(ft_watireste(s)) == 3)
		{
			ft_strscat(ft_getdict(rush, ft_watireste(ft_watireste(s))), d);
			ft_strscat(ft_getdict(rush, ft_watisuite(ft_watireste(s))), d);
			ft_strscat(ft_getdict(rush, ft_watidec(ft_watireste(s + 1))), d);
			ft_strscat(ft_getdict(rush, ft_watiunit(ft_watireste(s + 1))), d);
		}
		ft_strscat(ft_getdict(rush, ft_watisuite(s)), d);
		s += 3;
	}
	if (ft_strlen(ft_watisuite(s)) == 3)
	{
		ft_strscat(ft_getdict(rush, ft_watireste(s)), d);
		ft_strscat(ft_getdict(rush, ft_watisuite(s)), d);
		s += 1;
	}
	ft_strscat(ft_getdict(rush, ft_watidec(s)), d);
	ft_strscat(ft_getdict(rush, ft_watiunit(s)), d);
}
