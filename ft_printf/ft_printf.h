/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@students.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:53:52 by isel-kha          #+#    #+#             */
/*   Updated: 2025/03/25 23:53:52 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_puthexa(unsigned long n, char x);
int	ft_putunbr(unsigned int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);
#endif
