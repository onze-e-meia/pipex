/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:35:38 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

static void	ft_zero_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->left = 0;
	flags->with = 0;
	flags->dot = 0;
	flags->prcsn = 0;
	flags->alt = 0;
	flags->spc = 0;
	flags->sign = 0;
}

static int	ft_set_flags(char ch, t_flags *flags)
{
	if (ch == '0')
		flags->zero = 1;
	else if (ch == '-')
		flags->left = 1;
	else if (ch == '#')
		flags->alt = 1;
	else if (ch == ' ')
		flags->spc = 1;
	else if (ch == '+')
		flags->sign = 1;
	return (1);
}

static int	ft_isdigit(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

static int	ft_atoi(int ch, int *flag)
{
	*flag = 10 * *flag + (ch - '0');
	return (1);
}

int	pf_atoi_flags(const char *str, t_flags *flags)
{
	int	count;

	count = 0;
	ft_zero_flags(flags);
	while (*str == '-' || *str == '#' || *str == ' '
		|| *str == '+' || *str == '0')
	{
		count += ft_set_flags(*(str++), flags);
		while (flags->zero && ft_isdigit(*str))
			count += ft_atoi(*(str++), &flags->prcsn);
	}
	while (ft_isdigit(*str))
		count += ft_atoi(*(str++), &flags->with);
	if (*str == '.' && str++ && ++count)
	{
		if (flags->prcsn > 0)
			flags->with = flags->prcsn;
		flags->zero = 0;
		flags->prcsn = 0;
		flags->dot = 1;
	}
	while (ft_isdigit(*str))
		count += ft_atoi(*(str++), &flags->prcsn);
	return (count);
}
