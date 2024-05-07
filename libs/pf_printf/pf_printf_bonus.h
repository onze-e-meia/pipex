/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:44:06 by tforster          #+#    #+#             */
/*   Updated: 2024/04/06 13:41:17 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINTF_BONUS_H
# define PF_PRINTF_BONUS_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# define DEC_BASE "0123456789"

typedef struct s_char
{
	char			content;
	struct s_char	*next;
}					t_char;

typedef struct s_flags
{
	int	zero;
	int	left;
	int	with;
	int	dot;
	int	prcsn;
	int	alt;
	int	spc;
	int	sign;
}		t_flags;

t_char	*pf_newnode(char content);
t_char	*pf_lstlast(t_char *lst);
void	pf_lstadd_back(t_char **lst, t_char *new_node);
void	pf_lstadd_front(t_char **lst, t_char *new_node);
void	pf_lstclear(t_char **lst);

int		pf_addchar(char ch, t_char **lst);
int		pf_addstr(char *str, t_char **lst);
int		pf_addstr_len(char *str, t_char **lst, int len);
int		pf_addnbr_base(unsigned long nbr, char *base, t_char **lst);
int		pf_printf(const char *str, ...);

int		pf_atoi_flags(const char *str, t_flags *flags);

int		pf_flag_space(t_char **lst, t_flags flags);
int		pf_flag_alt(t_char **lst, char conv);
int		pf_flag_sign(t_char **lst, t_flags flags);
int		pf_flag_with(t_char **lst, int with, int left);
int		pf_flag_prcsn(t_char **lst, int prcsn);

int		pf_char_conv(va_list ap, t_char **lst, t_flags flags);
int		pf_str_conv(va_list ap, t_char **lst, t_flags flags);
int		pf_ptr_conv(va_list ap, t_char **lst, t_flags flags);
int		pf_digit_int(va_list ap, t_char **lst, t_flags flags);
int		pf_un_hex(va_list ap, t_char **lst, t_flags flags, char conv);

#endif
