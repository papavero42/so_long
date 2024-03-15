/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:48:39 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/02/26 12:00:42 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnlstrchr(const char *s, int c)
{
	unsigned char	*str;

	c = '\n';
	str = (unsigned char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}

size_t	ft_gnlstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_gnlstrjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * (ft_gnlstrlen(s1) + ft_gnlstrlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	return (str);
}

void	*ft_gnlcalloc(size_t count, size_t size)
{
	void			*p;
	unsigned char	*pp;
	size_t			n;

	n = count * size;
	p = malloc(n);
	if (p == NULL)
		return (p);
	pp = p;
	while (n)
	{
		*pp++ = 0;
		--n;
	}
	return (p);
}

char	*ft_gnlsubstr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start >= ft_gnlstrlen(s))
	{
		start = ft_gnlstrlen(s);
		len = 0;
	}
	if (len + start > ft_gnlstrlen(s))
	{
		len = ft_gnlstrlen(s) - start;
	}
	str = ft_gnlcalloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
