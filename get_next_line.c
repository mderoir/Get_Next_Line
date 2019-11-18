/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:28:31 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/18 17:00:58 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
    static char *str;
    int i;

    i = 0;
    if (error_check(fd, &str, line) == -1)
        return (-1);
    str = readline(fd, str);
    if (str[i])
    {
        while (str[i] != '\n' && str[i])
            i++;
        if (i == 0)
            (*line) = ft_strdup("");
        else
        {
            (*line) = ft_substr(str, 0, i);
            str = &str[i+1];
        }
        return (1);
    }
    else
        (*line) = ft_strdup("");
    return (0);
}