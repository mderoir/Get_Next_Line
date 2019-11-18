/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:28:35 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/18 11:28:35 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int error_check(int fd, char **str, char **line)
{ 
    if (fd == -1 || line == NULL)
        return (-1);
    if (!*str)
    {
        if(!(*str = malloc(sizeof(char*) * (BUFFER_SIZE + 1))))
            return (-1);
    }

    return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*readline(int fd, char *str)
{
    char buffer[BUFFER_SIZE + 1];
    int octet_read;
    
    while ((octet_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[octet_read] = '\0';
        str = ft_strjoin(str, buffer);
    }
    return (str);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

void    ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = malloc(len * sizeof(char))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	while (s2[len - ft_strlen(s1)])
	{
		str[len] = s2[len - ft_strlen(s1)];
		len++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

char		*ft_strdup( char *s1)
{
	char	*str;
	if (!(str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}