/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:08:10 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

int	pf_flag_space(t_char **lst, t_flags flags)
{
	if (flags.sign > 0)
		return (0);
	pf_lstadd_front(lst, pf_newnode(' '));
	return (1);
}

int	pf_flag_sign(t_char **lst, t_flags flags)
{
	if (flags.sign > 0)
		pf_lstadd_front(lst, pf_newnode('+'));
	else
		pf_lstadd_front(lst, pf_newnode('-'));
	return (1);
}

int	pf_flag_alt(t_char **lst, char conv)
{
	if (conv == 'x')
		pf_lstadd_front(lst, pf_newnode('x'));
	else if (conv == 'X')
		pf_lstadd_front(lst, pf_newnode('X'));
	pf_lstadd_front(lst, pf_newnode('0'));
	return (2);
}

int	pf_flag_prcsn(t_char **lst, int prcsn)
{
	int	len;

	len = prcsn;
	while (prcsn--)
		pf_lstadd_front(lst, pf_newnode('0'));
	return (len);
}

int	pf_flag_with(t_char **lst, int with, int left)
{
	int	len;

	len = with;
	while (with--)
	{
		if (left)
			pf_lstadd_back(lst, pf_newnode(' '));
		else
			pf_lstadd_front(lst, pf_newnode(' '));
	}
	return (len);
}
