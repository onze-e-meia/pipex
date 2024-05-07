/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:31:18 by tforster          #+#    #+#             */
/*   Updated: 2024/04/05 18:33:22 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_args	init_args(int argc, char **argv, char **envp)
{
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	args.envp = envp;
	return (args);
}

char	**envp_path(char **envp)
{
	char	**path;

	path = envp;
	while (*path && ft_strncmp(*path, "PATH=", ft_strlen("PATH=")))
		path++;
	if (!*path)
	{
		pf_printf(STDERR_FILENO, "No Path found\n");
		return (NULL);
	}
	*path += ft_strlen("PATH=");
	return (ft_split(*path, ':'));
}

void	free_envp_path(char **paths)
{
	char	**ptr;

	if (!*paths)
		return ;
	ptr = paths;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(paths);
}
