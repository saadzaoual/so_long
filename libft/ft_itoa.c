/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:56:26 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:56:29 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_size(long nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		size++;
	}
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	int		is_neg;
	long	nb;
	char	*str;

	size = count_size((long) n);
	str = (char *) malloc(sizeof(char) * size + 1);
	nb = n;
	if (str == NULL)
		return (NULL);
	is_neg = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
		is_neg = 1;
	}
	str[size] = '\0';
	while (size > (size_t) is_neg)
	{
		str[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}
