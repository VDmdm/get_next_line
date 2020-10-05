/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:43:34 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/13 22:06:37 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		size;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if ((str = (char *)malloc(len + 1)))
	{
		str[0] = 0;
		ft_strlcat(str, &s[start], len + 1);
		return (str);
	}
	return (0);
}

int			ft_write_line(int fd, char **line, char **str)
{
	size_t		len;
	char		*tmp;

	tmp = 0;
	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != 0)
		len++;
	if (str[fd][len] == '\n')
		if (!(tmp = ft_strdup(str[fd] + len + 1)))
			return (-1);
	if (!(*line = ft_substr(str[fd], 0, len)))
		return (-1);
	free(str[fd]);
	str[fd] = tmp;
	if (tmp)
		return (1);
	return (0);
}

int			ft_exit_gnl(int fd, char **line, char **str, int ret)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && str[fd] == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_write_line(fd, line, str));
}

int			ft_start_gnl(int fd, char **line)
{
	int			ret;
	char		*buff;
	static char	*str[14000];
	char		*tmp;

	if (!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup("");
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(buff);
	return (ft_exit_gnl(fd, line, str, ret));
}

int			get_next_line(int fd, char **line)
{
	char	tmp[1];
	int		ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if ((ret = read(fd, tmp, 0)) < 0)
		return (-1);
	return (ft_start_gnl(fd, line));
}
