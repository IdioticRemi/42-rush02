/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:13:33 by tschlege          #+#    #+#             */
/*   Updated: 2021/08/22 17:13:36 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

int	main(int argc, t_str *argv)
{
	t_rush	rush;
	t_str	s;

	if (argc > 3 || argc < 2)
		return (0);
	if (argc == 3)
		rush = ft_dictparse(argv[1]);
	else
		rush = ft_dictparse("dicts/numbers.dict");
	if (ft_stronlyhas(argv[argc - 1], "0123456789"))
		return (0);
	s = malloc(ft_watisum(rush, argv[argc - 1]) + 1);
	s[0] = '\0';
	ft_waticat(rush, s, argv[argc - 1]);
	if (s[ft_strlen(s) - 1] == ' ')
		s[ft_strlen(s) - 1] = '\0';
	ft_putstr(s);
}
