/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:11:24 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

int	pf_char_conv(va_list ap, t_char **lst, t_flags flags)
{
	int		len;
	t_char	*temp;

	temp = NULL;
	len = pf_addchar(va_arg(ap, unsigned int), &temp);
	if (flags.with > len)
		len += pf_flag_with(&temp, flags.with - len, flags.left);
	pf_lstadd_back(lst, temp);
	return (len);
}

int	pf_str_conv(va_list ap, t_char **lst, t_flags flags)
{
	int		len;
	t_char	*temp;

	len = 0;
	temp = NULL;
	if (flags.dot)
		len += pf_addstr_len(va_arg(ap, char *), &temp, flags.prcsn);
	else
		len += pf_addstr(va_arg(ap, char *), &temp);
	if (flags.with > len)
		len += pf_flag_with(&temp, flags.with - len, flags.left);
	pf_lstadd_back(lst, temp);
	return (len);
}

int	pf_ptr_conv(va_list ap, t_char **lst, t_flags flags)
{
	int				len;
	t_char			*temp;
	unsigned long	mmry_add;

	mmry_add = va_arg(ap, unsigned long);
		temp = NULL;
	if (mmry_add == 0)
		len = pf_addstr("(nil)", &temp);
	else
		len = pf_addstr("0x", &temp) + pf_addnbr_base(mmry_add, HEX_LOW, &temp);
	if (flags.with > len)
		len += pf_flag_with(&temp, flags.with - len, flags.left);
	pf_lstadd_back(lst, temp);
	return (len);
}
