/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:45:13 by tforster          #+#    #+#             */
/*   Updated: 2024/04/05 14:48:47 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parse_cmd(char *str, t_parse *parse, t_parse **ptr, int *index);
static void	parse_txt(char *str, t_parse *parse, t_parse **ptr, int *index);

t_parse	*parse_param(char *str)
{
	t_parse	*parse;
	t_parse	*ptr;
	int		index;

	parse = parse_new(CMD, 0);
	ptr = parse;
	index = 0;
	while (str[index])
	{
		while (ft_is_tab(str[index]) && ptr->type == CMD)
		{
			index++;
			ptr->start++;
		}
		if (str[index] == '\'')
		{
			ptr->type = TEXT;
			ptr->start++;
		}
		if (ptr->type == CMD && str[index])
			parse_cmd(str, parse, &ptr, &index);
		else if (ptr->type == TEXT && str[index])
			parse_txt(str, parse, &ptr, &index);
	}
	return (parse);
}

static void	parse_cmd(char *str, t_parse *parse, t_parse **ptr, int *index)
{
	(*ptr)->size++;
	if (ft_is_tab(str[++(*index)]))
	{
		parse_add_back(&parse, parse_new(CMD, ++(*index)));
		*ptr = parse_last(parse);
	}
}

static void	parse_txt(char *str, t_parse *parse, t_parse **ptr, int *index)
{
	(*ptr)->size++;
	(*index)++;
	if (str[*index] == '\'')
	{
		(*ptr)->size--;
		parse->close = 1;
		if (ft_is_tab(str[++(*index)]))
		{
			parse_add_back(&parse, parse_new(CMD, ++(*index)));
			*ptr = parse_last(parse);
		}
	}
}
