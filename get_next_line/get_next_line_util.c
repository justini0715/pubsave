#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*sc;

	sc = s;
	while (*sc && *(++sc))
		;
	return (sc - s);
}

// int	ft_strchr(const char *s, int c)
// {
// 	if (!s)
// 		return (NULL);
// 	while (*s && *(s++) != c)
// 		;
// 	if (*s == c)
// 		return ((char *)s);
// 	return (NULL);
// }

char	*ft_strchr(const char *s, int c)
{
	if (!s--)
		return (NULL);
	while (*++s)
		if (*s == c % 128)
			return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*sc;
	char	*st;

	st = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!st)
		return (NULL);
	sc = st;
	while (*s)
		*sc++ = *s++;
	*sc = 0;
	return (st);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	total;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
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
	char	*sc;
	char	*res;

	if (s && start > ft_strlen(s))
		len = 0;
	if (!(s + start))
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	sc = res;
	while (len-- && *(s + start))
		*sc++ = *(s++ + start);
	*sc = 0;
	return (res);
}