/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:44:43 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/13 22:10:44 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len_s;

	if (!s1)
		return (0);
	len_s = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(len_s + 1)))
	{
		str[0] = 0;
		ft_strlcat(str, s1, len_s + 1);
		ft_strlcat(str, s2, len_s + 1);
		return (str);
	}
	return (0);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len_s;
	size_t len_d;

	i = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (size > len_d)
	{
		while (*src != '\0' && ((len_d + i) != (size - 1)))
			dest[len_d + i++] = *src++;
	}
	if (size)
		dest[len_d + i] = '\0';
	return (len_s + (size < len_d ? size : len_d));
}

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0' && str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (*str == ch)
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (*str != 0)
		{
			i++;
			str++;
		}
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	size_t	len;
	size_t	str_len;

	if (!(str_len = ft_strlen(src) + 1))
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * str_len)))
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		str[len] = src[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
