#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	int		a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len < maxlen)
	{
		if (!*s)
			break ;
		len++;
		s++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int	ft_wc(char const *s, char c)
{
	unsigned int	wc;

	wc = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		wc++;
		while (*s && *s == c)
			s++;
	}
	return (wc);
}

void	ft_matfree(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
	str = NULL;
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	if (dup == 0)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

char	*ft_strnew(size_t n)
{
	char	*s;

	s = (char *)malloc(n + 1);
	if (s)
		memset(s, 0, n + 1);
	return (s);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (len != 0)
	{
		str[i] = s[start];
		start++;
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}


char	**ft_strsplit(char const *s, char c)
{
	char		**str;
	const char	*end;
	int			i;

	i = 0;
	if (!s || !(str = (char **)malloc((ft_wc(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		end = s;
		while (*end && *end != c)
			end++;
		if (!(*(str + i++) = ft_strsub(s, 0, end - s)))
		{
			ft_matfree(str, i);
			return (NULL);
		}
		s = end;
		while (*s && *s == c)
			s++;
	}
	*(str + i) = NULL;
	return (str);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (*p1 && (*p1 == *p2))
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *s3;
    int     i;
    int     j;
    if (!s1 || !s2)
        return (NULL);
    s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!s3)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[j + i] = s2[j];
        j++;
    }
    s3[j + i] = '\0';
    free (s1);
    free (s2);
    return (s3);
}

int ft_strchr(const char *s, char c)
{
	while (*s != c)
		if (!*s++)
			return (0);
	return (1);
}