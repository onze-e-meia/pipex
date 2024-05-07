/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:22:49 by tforster          #+#    #+#             */
/*   Updated: 2024/04/06 13:39:38 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	end_process(t_pipex pipex, char *file);

int	check_file_open(t_pipex pipex, char *file, int mode)
{
	int		fd;

	fd = 0;
	if (mode == O_RDONLY)
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
			end_process(pipex, file);
	}
	else if (mode == O_WRONLY)
	{
		fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (fd < 0)
			end_process(pipex, file);
	}
	return (fd);
}

static void	end_process(t_pipex pipex, char *file)
{
	pf_printf(STDERR_FILENO, "%s: %s\n", file, strerror(errno));
	close_pipe_fd(pipex.fd);
	if (pipex.signal[0] > 0 || pipex.signal[1] > 0)
		close_pipe_fd(pipex.signal);
	exit(EXIT_FAILURE);
}
