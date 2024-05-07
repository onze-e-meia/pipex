/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:17:47 by tforster          #+#    #+#             */
/*   Updated: 2024/04/06 13:34:28 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	end_signal(int pipe[2])
{
	close(pipe[0]);
	write(pipe[1], "END", 3);
	close(pipe[1]);
}

static void	start_signal(int pipe[2])
{
	char	buffer[3];

	close(pipe[1]);
	read(pipe[0], buffer, 3);
	close(pipe[0]);
}

static void	firts_process(t_args args, t_pipex pipex)
{
	char	**path;
	int		fd;
	char	**cmd;

	fd = check_file_open(pipex, args.argv[1], O_RDONLY);
	cmd = parse_args(args.argv[pipex.cmd_nb + 1]);
	path = envp_path(args.envp);
	pipex.status = check_cmd_access(cmd, path);
	dup2(fd, STDIN_FILENO);
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(fd);
	close_pipe_fd(pipex.fd);
	end_signal(pipex.signal);
	if (pipex.status == 0)
		pipex.status = execve(cmd[0], cmd, args.envp);
	else
	{
		free_envp_path(path);
		free_args(cmd);
	}
	exit (pipex.status);
}

static void	last_process(t_args args, t_pipex pipex)
{
	char	**path;
	int		fd;
	char	**cmd;

	start_signal(pipex.signal);
	fd = check_file_open(pipex, args.argv[args.argc - 1], O_WRONLY);
	cmd = parse_args(args.argv[pipex.cmd_nb + 1]);
	path = envp_path(args.envp);
	pipex.status = check_cmd_access(cmd, path);
	dup2(pipex.fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close_pipe_fd(pipex.fd);
	if (pipex.status == 0)
		pipex.status = execve(cmd[0], cmd, args.envp);
	else
	{
		free_envp_path(path);
		free_args(cmd);
	}
	exit (pipex.status);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;
	t_pipex	pipex;

	check_nb_args(argc, 4, 4);
	check_pipe(&pipex);
	args = init_args(argc, argv, envp);
	pipex.cmd_nb = 1;
	pipex.pid = fork();
	if (pipex.pid == 0)
		firts_process(args, pipex);
	pipex.cmd_nb++;
	pipex.pid = fork();
	if (pipex.pid == 0)
		last_process(args, pipex);
	close_pipe_fd(pipex.fd);
	close_pipe_fd(pipex.signal);
	pipex.status = 0;
	waitpid(pipex.pid, &pipex.status, 0);
	if (WIFEXITED(pipex.status))
		return (WEXITSTATUS(pipex.status));
	return (pipex.status);
}
