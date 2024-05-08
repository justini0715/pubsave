/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changwpa <changwpa@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:42:13 by changwpa          #+#    #+#             */
/*   Updated: 2024/04/27 18:06:22 by changwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*split_line(char **save)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*save)[i] != 10)
		i++;
	line = ft_substr(*save, 0, i + 1);
	tmp = *save;
	*save = ft_substr(*save, i + 1, ft_strlen(*save) - i - 1);
	free(tmp);
	return (line);
}

int	get_text(int fd, char **buff, char **save)
{
	int		byte;
	char	*prev_save;

	byte = 1;
	while (!ft_strchr(*save, '\n') && byte)
	{
		byte = read(fd, *buff, BUFF_SIZE);
		if (byte == -1)
			return (byte);
		(*buff)[byte] = 0;
		prev_save = *save;
		*save = ft_strjoin(prev_save, *buff);
		free(prev_save);
	}
	return (byte);
}

char	*set_line(int fd, char **buff, char **save)
{
	int		read_size;
	char	*prev_line;

	read_size = get_text(fd, buff, save);
	if (read_size == -1)
		return (NULL);
	if (ft_strchr(*save, '\n'))
		prev_line = split_line(save);
	else if (**save != 0 && read_size != 0)
		prev_line = ft_strdup(*save);
	else
	{
		prev_line = ft_strdup(*save);
		*prev_line = 0;
	}
	return (prev_line);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*buff;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFF_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (0);
	if (!save[fd])
		save[fd] = ft_strdup("");
	line = set_line(fd, &buff, &save[fd]);
	free(buff);
	if (*save[fd] == 0 && *line == 0)
	{
		free(save[fd]);
		free(line);
		return (0);
	}
	if (*line == 0)
	{
		line = ft_strdup(save[fd]);
		*save[fd] = 0;
	}
	return (line);
}
