/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:52:00 by szaoual           #+#    #+#             */
/*   Updated: 2024/11/21 16:40:28 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		counter += ft_putchar('-');
	}
	if (n < 10)
		counter += ft_putchar('0' + n);
	else
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	return (counter);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, str + (i++), 1);
	return (i);
}

int	ft_puthexa(unsigned long n, char x)
{
	char	*lwbase;
	char	*upbase;
	int		cont;

	cont = 0;
	lwbase = "0123456789abcdef";
	upbase = "0123456789ABCDEF";
	if (n < 16)
	{
		if (x == 'x')
			cont += ft_putchar(*(n + lwbase));
		if (x == 'X')
			cont += ft_putchar(*(n + upbase));
	}
	if (n >= 16)
	{
		cont += ft_puthexa(n / 16, x);
		cont += ft_puthexa(n % 16, x);
	}
	return (cont);
}

int	ft_putunbr(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n < 10)
		cont += ft_putchar('0' + n);
	else
	{
		cont += ft_putunbr(n / 10);
		cont += ft_putunbr(n % 10);
	}
	return (cont);
}
