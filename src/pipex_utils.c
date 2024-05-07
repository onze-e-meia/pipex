/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:28:31 by tforster          #+#    #+#             */
/*   Updated: 2024/04/06 13:34:06 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_nb_args(int argc, int min, int max)
{
	if (argc - 1 < min)
	{
		pf_printf(STDERR_FILENO,
			"Error: Too few parameters (%d), must have 4\n", argc - 1);
		pf_printf(STDERR_FILENO,
			"$> ./pipex \"infile\" \"cmd_01\" \"cmd_02\" \"outfile\"\n");
		exit(EXIT_FAILURE);
	}
	if (argc - 1 > max)
	{
		pf_printf(STDERR_FILENO,
			"Error: Too many parameters (%d), must have 4\n", argc - 1);
		pf_printf(STDERR_FILENO,
			"$> ./pipex \"infile\" \"cmd_01\" \"cmd_02\" \"outfile\"\n");
		exit(EXIT_FAILURE);
	}
}

void	check_pipe(t_pipex *pipex)
{
	if (pipe(pipex->fd) == -1 || pipe(pipex->signal) == -1)
	{
		pf_printf(STDERR_FILENO, "Pipe fail");
		exit(EXIT_FAILURE);
	}
}

void	close_pipe_fd(int pipe[2])
{
	close(pipe[0]);
	close(pipe[1]);
}
