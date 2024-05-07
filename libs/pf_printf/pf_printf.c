/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:50 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 16:02:15 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

int	pf_digit_int(int fd, va_list ap)
{
	long	nbr;
	int		len;

	nbr = va_arg(ap, int);
	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len = pf_putchar(fd, '-');
	}
	return (pf_putnbr_base(fd, nbr, DEC_BASE) + len);
}

int	pf_ptr_conversion(int fd, va_list ap)
{
	unsigned long	memory_add;

	memory_add = va_arg(ap, unsigned long);
	if (memory_add == 0)
		return (pf_putstr(fd, "(nil)"));
	else
		return (pf_putstr(fd, "0x") + pf_putnbr_base(fd, memory_add, HEX_LOW));
}

int	ft_pick_conv(int fd, const char *str, va_list ap)
{
	if (*str == 'c')
		return (pf_putchar(fd, va_arg(ap, unsigned int)));
	else if (*str == 's')
		return (pf_putstr(fd, va_arg(ap, char *)));
	else if (*str == 'p')
		return (pf_ptr_conversion(fd, ap));
	else if (*str == 'd' || *str == 'i')
		return (pf_digit_int(fd, ap));
	else if (*str == 'u')
		return (pf_putnbr_base(fd, va_arg(ap, unsigned int), DEC_BASE));
	else if (*str == 'x')
		return (pf_putnbr_base(fd, va_arg(ap, unsigned int), HEX_LOW));
	else if (*str == 'X')
		return (pf_putnbr_base(fd, va_arg(ap, unsigned int), HEX_UPP));
	else if (*str == '%')
		return (pf_putchar(fd, '%'));
	return (0);
}

int	ft_check_percent(int fd, const char *str, va_list ap)
{
	int		len;

	len = 0;
	while (*str)
	{
		if (*(str) != '%')
			len += pf_putchar(fd, *(str));
		else if (*(str++) == '%')
			len += ft_pick_conv(fd, str, ap);
		str++;
	}
	return (len);
}

int	pf_printf(int fd, const char *fmt, ...)
{
	int		len;
	va_list	ap;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	len = ft_check_percent(fd, fmt, ap);
	va_end(ap);
	return (len);
}
