#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sc;
	char	*res;

	if (s && start > strlen(s))
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

int	main(void)
{
	char	*s;
	char	*res;

	s = "abcdefghij";
	// res = ft_substr(s, 5, 10);
	res = ft_substr(s, 5, 10);
	printf("%s\n", res);
	free(res);
	// printf("%d\n", (char *)NULL);
}
