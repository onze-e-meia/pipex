/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_addnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:09:01 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

static static int	ft_strlen(char *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
		index++;
	return (index);
}

static int	ft_base(unsigned long nbr, int base_size, char *base, t_char **lst)
{
	unsigned long	remainder;
	char			ch;
	int				len;

	len = 1;
	if (nbr < (unsigned long) base_size)
	{
		ch = base[nbr];
		pf_lstadd_back(lst, pf_newnode(ch));
	}
	else
	{
		remainder = nbr % base_size;
		nbr = nbr / base_size;
		len += ft_base(nbr, base_size, base, lst);
		ch = base[remainder];
		pf_lstadd_back(lst, pf_newnode(ch));
	}
	return (len);
}

int	pf_addnbr_base(unsigned long nbr, char *base, t_char **lst)
{
	int		base_size;
	int		len;

	len = 0;
	base_size = ft_strlen(base);
	if (base_size > 1)
		len += ft_base(nbr, base_size, base, lst);
	return (len);
}
