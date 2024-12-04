/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changwpa <changwpa@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:41:23 by changwpa          #+#    #+#             */
/*   Updated: 2024/04/27 17:55:13 by changwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*sc;

	sc = s;
	while (*sc && *(++sc))
		;
	return (sc - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*sc;
	char	*st;

	st = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!st)
		return (0);
	sc = st;
	while (*s)
		*st++ = *s++;
	*st = 0;
	return (sc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	total;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	else if (!s1 && !s2)
		return (0);
	total = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (total + 1));
	if (!res)
		return (NULL);
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (res - total);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	char	*s1;
	size_t	cnt;

	if (s && (start > ft_strlen(s)))
		len = 0;
	s1 = (char *)(s + start);
	if (!s1)
		return (NULL);
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!(d))
		return (0);
	cnt = len;
	while (len--)
		*d++ = *s1++;
	*d = 0;
	return (d - cnt);
}
