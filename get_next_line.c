/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:55:09 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:55:11 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strchr_(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

static char	*ft_strjoin_(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*res;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ptr = res;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (res);
}

static char	*ft_read_to_str_left(int fd, char *str_left)
{
	char	*buffer;
	int		read_bytes;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str_left), NULL);
	while (!ft_strchr_(str_left, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(str_left), free(buffer), NULL);
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin_(str_left, buffer);
		if (!tmp)
			return (free(str_left), free(buffer), NULL);
		free(str_left);
		str_left = tmp;
	}
	free(buffer);
	return (str_left);
}

char	*get_next_line(int fd)
{
	static char	*str_left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(str_left), NULL);
	str_left = ft_read_to_str_left(fd, str_left);
	if (!str_left)
		return (NULL);
	return (ft_extract_line(&str_left));
}
