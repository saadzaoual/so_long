/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:53:47 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:53:47 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(char format, va_list args)
{
	int	counter;

	counter = 0;
	if (format == 's')
		counter += ft_putstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		counter += ft_putnbr(va_arg(args, int));
	if (format == 'c')
		counter += ft_putchar(va_arg(args, int));
	if (format == 'x' || format == 'X')
		counter += ft_puthexa(va_arg(args, unsigned int), format);
	if (format == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_puthexa(va_arg(args, unsigned long), 'x');
	}
	if (format == 'u')
		counter += ft_putunbr(va_arg(args, unsigned int));
	if (format == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	char	*p;
	int		cont;

	if (!format || write(1, 0, 0) == -1)
		return (-1);
	va_start(list, format);
	cont = 0;
	p = (char *) format;
	while (*p)
	{
		if (*p == '%')
		{
			if (*(p + 1) == '\0')
				return (cont);
			cont += ft_flags(*(++p), list);
		}
		else
			cont += ft_putchar(*p);
		p++;
	}
	va_end(list);
	return (cont);
}
