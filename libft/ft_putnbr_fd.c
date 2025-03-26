/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:57:29 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:57:31 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	print_nb(long n, int fd)
{
	if (n / 10)
	{
		print_nb(n / 10, fd);
		print_nb(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	print_nb(nb, fd);
}
