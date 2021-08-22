/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:49:21 by tjolivea          #+#    #+#             */
/*   Updated: 2021/08/22 11:49:23 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <rush02.h>

t_bool	ft_file_exists(t_str path)
{
	int		fd;
	t_bool	res;

	fd = open(path, O_RDONLY);
	res = TRUE;
	if (fd == -1)
		res = FALSE;
	close(fd);
	return (res);
}

t_uint 	ft_filelen(t_str path)
{
	t_uint	filelen;
	int		fd;
	char	buf[1];

	if (!ft_file_exists(path))
		return (0);
	fd = open(path, O_RDONLY);
	filelen = 0;
	while (read(fd, buf, 1))
		filelen++;
	close(fd);
	return (filelen);
}

t_file	ft_fileread(t_str path)
{
	t_file	file;
	int		fd;

	file.length = ft_filelen(path);
	file.content = malloc(sizeof(char) * (file.length + 1));
	if (!file.content)
		return (file);
	fd = open(path, O_RDONLY);
	if (ft_file_exists(path))
		read(fd, file.content, file.length);
	close(fd);
	file.content[file.length] = '\0';
	return (file);
}
