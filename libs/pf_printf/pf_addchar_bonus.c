/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_addchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:32:46 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

int	pf_addchar(char ch, t_char **lst)
{
	pf_lstadd_back(lst, pf_newnode(ch));
	return (1);
}
