/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:33:06 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:55:21 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

int	pf_putstr(int fd, char *str)
{
	int	len;

	if (!str)
	{
		len = pf_putstr(fd, "(null)");
		return (len);
	}
	len = 0;
	while (str && *str && ++len)
		pf_putchar(fd, *str++);
	return (len);
}
