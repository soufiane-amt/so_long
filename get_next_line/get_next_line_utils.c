/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:42:11 by samajat           #+#    #+#             */
/*   Updated: 2022/02/05 14:47:27 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (len > ft_strlen(s) + 1)
		len = ft_strlen(s);
	substr = (char *) malloc (sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			substr[j] = s[i];
			j++;
		}
	}
	substr[j] = 0;
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*f_dest;
	const char	*f_src;
	char		*te_dest;
	const char	*te_src;
	size_t		i;

	i = 0;
	f_dest = (char *)dest;
	f_src = (const char *)src;
	if (src > dest)
		while (i++ < len)
			*f_dest++ = *f_src++;
	else
	{
		te_src = f_src + (len - 1);
		te_dest = f_dest + (len - 1);
		while (i++ < len)
			*te_dest-- = *te_src--;
	}
	return (dest);
}
