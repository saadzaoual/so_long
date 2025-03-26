/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:58:05 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:58:07 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc(len1 + len2 + 1);
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1, len1);
	ft_memcpy(newstr + len1, s2, len2);
	newstr[len1 + len2] = '\0';
	return (newstr);
}
