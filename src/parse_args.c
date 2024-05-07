/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:00:01 by tforster          #+#    #+#             */
/*   Updated: 2024/04/05 14:51:07 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	plt_args(char *str, t_parse *parse, char **parsed_arg, int nb_arg);

char	**parse_args(char *str)
{
	t_parse	*parse;
	char	**parsed_arg;
	int		nb_arg;

	parse = parse_param(str);
	if (!parse)
		return (NULL);
	nb_arg = parse_len(parse);
	parsed_arg = malloc((nb_arg + 1) * sizeof(char *));
	if (!parsed_arg)
		return (NULL);
	plt_args(str, parse, parsed_arg, nb_arg);
	parse_free(parse);
	return (parsed_arg);
}

static void	plt_args(char *str, t_parse *parse, char **parsed_arg, int nb_arg)
{
	t_parse	*ptr;
	int		index;
	int		j;

	ptr = parse;
	index = 0;
	while (index < nb_arg)
	{
		parsed_arg[index] = malloc((ptr->size + 1) * sizeof(char));
		if (!parsed_arg)
			exit(EXIT_FAILURE);
		j = 0;
		while (j < ptr->size)
		{
			parsed_arg[index][j] = str[ptr->start + j];
			j++;
		}
		parsed_arg[index][j] = '\0';
		ptr = ptr->next;
		index++;
	}
	parsed_arg[index] = NULL;
}

void	free_args(char **args)
{
	char	**ptr;

	ptr = args;
	while (ptr && *ptr)
		free (*ptr++);
	if (args)
		free (args);
}
