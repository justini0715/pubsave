/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:01:49 by root              #+#    #+#             */
/*   Updated: 2024/12/05 00:46:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

/*

read
while find \n
	if true
		cur and return
	else
		join

exception

1. line end == eof
2. line start == eof
3. 
*/

void	*read_line(int fd)
{
	char	*join;
	int			byte;
	int			cnt;
	t_line	*line_list;
	t_line	*top;

	line_list = (t_line *)malloc(sizeof(*line_list));
	if (!line_list)
		return ;
	top = line_list;
	byte = 1;
	cnt = 0;
	while (byte)
	{

		// 새 노드 생성 lstnew
		// 노드 할당
		// 읽기 데이터 삽입 line_list->content
		// 조건 및 예외처리
		line_list = (t_line *)malloc(sizeof(*line_list));
		if (!line_list)
			return ;
		line_list->buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		byte = read(fd, line_list->buff, BUFFER_SIZE);
		line_list->buff[BUFFER_SIZE] = 0;
		line_list->next = NULL;
		printf("%s", line_list->buff);
		cnt += byte;
		if (byte < 1 || strchr(line_list->buff, '\n'))
			break;
		line_list = line_list->next;
	}
	printf("ok\n");
	join = (char *)malloc(sizeof(char) * cnt + 1);
	while (line_list->buff)
	{
		// printf("%s", line_list->buff);
		strcpy(join, line_list->buff);
		line_list = line_list->next;
	}
}

char	*get_next_line(int fd)
{
	static char	**save;
	// char		*buff;
	// buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	read_line(fd);

	return (*save);
}

int	main(void)
{
	int	fd;
	char *res;

	fd = open("test.txt", O_RDONLY);
	// get_next_line(fd);
	read_line(fd);
	// printf("%s", res);
}
