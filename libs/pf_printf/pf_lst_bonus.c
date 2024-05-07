/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:01:43 by tforster          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:31 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf_bonus.h"

t_char	*pf_newnode(char content)
{
	t_char	*lst;

	lst = malloc(sizeof(t_char));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_char	*pf_lstlast(t_char *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	pf_lstadd_back(t_char **lst, t_char *new_node)
{
	t_char	*last;

	last = pf_lstlast(*lst);
	if (!last)
		*lst = new_node;
	else
		last->next = new_node;
}

void	pf_lstadd_front(t_char **lst, t_char *new_node)
{
	if (lst && new_node)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}

void	pf_lstclear(t_char **lst)
{
	t_char	*temp;

	if (!lst)
		return ;
	while (lst && *lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}
