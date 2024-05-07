/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:50 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

int	ft_pick_conv(const char *str, va_list ap, t_char **lst, t_flags flags)
{
	if (*str == 'c')
		return (pf_char_conv(ap, lst, flags));
	else if (*str == 's')
		return (pf_str_conv(ap, lst, flags));
	else if (*str == 'p')
		return (pf_ptr_conv(ap, lst, flags));
	else if (*str == 'd' || *str == 'i')
		return (pf_digit_int(ap, lst, flags));
	else if (*str == 'u')
		return (pf_un_hex(ap, lst, flags, 'u'));
	else if (*str == 'x')
		return (pf_un_hex(ap, lst, flags, 'x'));
	else if (*str == 'X')
		return (pf_un_hex(ap, lst, flags, 'X'));
	else if (*str == '%')
		return (pf_addchar('%', lst));
	return (0);
}

int	ft_check_flags(const char *str, va_list ap, t_char **lst)
{
	int		len;
	t_flags	flags;

	len = 0;
	while (*str)
	{
		if (*(str) != '%')
			len += pf_addchar(*(str), lst);
		else if (*(str++) == '%')
		{
			str += pf_atoi_flags(str, &flags);
			len += ft_pick_conv(str, ap, lst, flags);
		}
		str++;
	}
	return (len);
}

int	pf_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;
	t_char	*lst;
	t_char	*temp;

	if (!fmt)
		return (-1);
	lst = NULL;
	va_start(ap, fmt);
	len = ft_check_flags(fmt, ap, &lst);
	va_end(ap);
	temp = lst;
	while (lst)
	{
		write(1, &lst->content, 1);
		lst = lst->next;
	}
	pf_lstclear(&temp);
	return (len);
}
