/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_addstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:33:06 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

int	pf_addstr(char *str, t_char **lst)
{
	int	len;

	if (!str)
		return (pf_addstr("(null)", lst));
	len = 0;
	while (str && *str && ++len)
		pf_addchar(*str++, lst);
	return (len);
}

int	pf_addstr_len(char *str, t_char **lst, int len)
{
	int	size;

	if (!str && len >= 6)
		return (pf_addstr("(null)", lst));
	size = 0;
	while ((len-- > 0) && str && *str && ++size)
		pf_addchar(*str++, lst);
	return (size);
}
