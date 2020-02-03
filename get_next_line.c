/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:28:31 by mderoir           #+#    #+#             */
/*   Updated: 2020/02/03 16:12:19 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "limits.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*mem;

	i = 0;
	if (!(mem = malloc(count * size)))
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int		line_cpy(int const fd, char **line, char **str)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		(*line) = ft_substr(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][len] == '\0')
	{
		(*line) = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str[255];
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	int			octet_read;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((octet_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[octet_read] = 0;
		if (str[fd] == NULL)
			str[fd] = ft_calloc(1, 1);
		tmp = ft_strjoin(str[fd], buffer);
		if (str[fd])
			free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (octet_read < 0)
		return (-1);
	else if (octet_read == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (line_cpy(fd, line, str));
}
