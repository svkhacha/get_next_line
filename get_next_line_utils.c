/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:21:31 by svkhacha          #+#    #+#             */
/*   Updated: 2022/04/12 21:07:15 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int			i;
	char		*dest;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest || !s1)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	len;
	char	*conc;

	len = ft_strlen(s1) + ft_strlen(s2);
	conc = malloc(sizeof(char) * (len + 1));
	if (!conc)
		return (0);
	i = 0;
	while (*s1)
		conc[i++] = *s1++;
	while (*s2)
		conc[i++] = *s2++;
	conc[i] = 0;
	return (conc);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*x;
	char	y;

	x = (char *)s;
	y = c;
	i = 0;
	if (!s)
		return (0);
	while (x[i] != '\0' && x[i] != y)
		i++;
	if (x[i] == y)
	{
		return (&x[i]);
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			lenstr;
	size_t			lenstart;
	unsigned int	i;

	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	lenstart = ft_strlen(s + start);
	if (lenstart < len)
		len = lenstart;
	substring = malloc(len + 1);
	i = 0;
	while (i < len && start + i < (unsigned int)lenstr)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
