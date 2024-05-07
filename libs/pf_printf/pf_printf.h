/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:44:06 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 16:06:57 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINTF_H
# define PF_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# define DEC_BASE "0123456789"

# define INT_MIN_ -2147483648

int	pf_putchar(int fd, char ch);
int	pf_putstr(int fd, char *str);
int	pf_putnbr_base(int fd, unsigned long nbr, char *base);
int	pf_printf(int fd, const char *str, ...);

#endif
