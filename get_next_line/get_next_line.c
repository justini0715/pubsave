#include "get_next_line.h"
#include <stdio.h>

char	*split_line(char **save)
{
	char	*line;
	char	*tmp;
	int	i;

	i = -1;
	while ((*save)[++i] && (*save)[i] != 10)
		;
	line = ft_substr(*save, 0, i + 1);
	tmp = *save;
	*save = ft_substr(*save, i + 1, ft_strlen(*save) - i - 1);
	free(tmp);
	return (line);
}

char	*set_line(int fd, char **save)
{
	char	*buff;
	char	*line;
	char	*tmp;
	int	read_byte;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(*save, 10) && read_byte)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		buff[read_byte] = 0;
		if (read_byte != BUFFER_SIZE)
			read_byte = 0;
		tmp = *save;
		*save = ft_strjoin(*save, buff);
		free(tmp);
	}
	free(buff);
	line = split_line(save);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char	*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	line = set_line(fd, &save);
	if (*save == 0 && *line == 0)
	{
		free(save);
		free(line);
		return (0);
	}
	if (*line == 0)
	{
		line = ft_strdup(save);
		*save = 0;
	}
	return (line);
}
int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	while (line = get_next_line(fd))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

/* bonus?

	if more fd --> can read line
	--> try read
		ok -> strdup
		no -> break;
	
	static char	**save; 
	if save --> doubly linked list
		[[fd3:save:[]->[]->[]]->[fd4:save:[]->[]->[]]->[fd5:save:[]->[]->[]]]
	typedef struct s_llist
	{
		// struct t_llist;
		char	*line;
		t_llist *next;
	}
	
	while (fd)
	{
		if (!*save[fd])
		{
			// free all
			// exit()
		}
		fd++
	}

	*/