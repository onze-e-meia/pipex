/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_nbs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:09:10 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

static void	ft_check_sign(long *nbr, t_flags *flags)
{
	*nbr *= -1;
	flags->sign = -1;
	flags->spc = 0;
	if (flags->zero)
		flags->prcsn -= 1;
}

int	pf_digit_int(va_list ap, t_char **lst, t_flags flags)
{
	long	nbr;
	int		len;
	t_char	*temp;

	len = 0;
	temp = NULL;
	nbr = va_arg(ap, int);
	if (nbr < 0)
		ft_check_sign(&nbr, &flags);
	if (!(nbr == 0 && flags.dot == 1 && flags.prcsn == 0))
		len += pf_addnbr_base(nbr, DEC_BASE, &temp);
	if (flags.prcsn > len)
		len += pf_flag_prcsn(&temp, flags.prcsn - len);
	if (flags.sign)
		len += pf_flag_sign(&temp, flags);
	if (flags.spc)
		len += pf_flag_space(&temp, flags);
	if (flags.with > len)
		len += pf_flag_with(&temp, flags.with - len, flags.left);
	pf_lstadd_back(lst, temp);
	return (len);
}

static char	*ft_pick_base(char conv)
{
	if (conv == 'x')
		return (HEX_LOW);
	else if (conv == 'X')
		return (HEX_UPP);
	return (DEC_BASE);
}

int	pf_un_hex(va_list ap, t_char **lst, t_flags flags, char conv)
{
	unsigned long	nbr;
	int				len;
	t_char			*temp;

	len = 0;
	temp = NULL;
	nbr = va_arg(ap, unsigned int);
	if (!(nbr == 0 && flags.dot == 1 && flags.prcsn == 0))
		len += pf_addnbr_base(nbr, ft_pick_base(conv), &temp);
	if (flags.prcsn > len)
		len += pf_flag_prcsn(&temp, flags.prcsn - len);
	if (flags.alt && nbr != 0)
		len += pf_flag_alt(&temp, conv);
	if (flags.with > len)
		len += pf_flag_with(&temp, flags.with - len, flags.left);
	pf_lstadd_back(lst, temp);
	return (len);
}
