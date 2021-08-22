/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:10:52 by tschlege          #+#    #+#             */
/*   Updated: 2021/08/22 17:10:55 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

t_str	ft_getdict(t_rush rush, t_str key)
{
	t_dict	*dic;

	dic = rush.dict;
	while (dic->text[0] && ft_strcmp(dic->number, key))
		dic++;
	return (dic->text);
}
