/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:55:05 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:55:07 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	ft_strlen_(const char *str)*/
/*{*/
/*	int	i;*/
/**/
/*	i = 0;*/
/*	if (!str)*/
/*		return (-1);*/
/*	while (str[i])*/
/*		i++;*/
/*	return (i);*/
/*}*/

static char	*ft_strlcpy_(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strdup_(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_update_remaining_str(char **str, int i)
{
	char	*temp;

	if ((*str)[i] == '\0')
	{
		free(*str);
		*str = NULL;
		return ;
	}
	temp = ft_strdup_(&(*str)[i]);
	if (!temp)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	free(*str);
	*str = temp;
}

char	*ft_extract_line(char **str)
{
	int		i;
	char	*line;

	i = 0;
	if (!*str)
		return (NULL);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ft_strlcpy_(line, *str, i + 1);
	ft_update_remaining_str(str, i);
	return (line);
}
