/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:09:01 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:56:47 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

static int	ft_strlen(char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
		index++;
	return (index);
}

int	ft_base(int fd, unsigned long nbr, int base_size, char *base)
{
	unsigned long	remainder;
	char			ch;
	int				len;

	len = 1;
	if (nbr < (unsigned long) base_size)
	{
		ch = base[nbr];
		write(fd, &ch, 1);
	}
	else
	{
		remainder = nbr % base_size;
		nbr = nbr / base_size;
		len += ft_base(fd, nbr, base_size, base);
		ch = base[remainder];
		write(fd, &ch, 1);
	}
	return (len);
}

int	pf_putnbr_base(int fd, unsigned long nbr, char *base)
{
	int		base_size;
	int		len;

	len = 0;
	base_size = ft_strlen(base);
	if (base_size > 1)
		len += ft_base(fd, nbr, base_size, base);
	return (len);
}
