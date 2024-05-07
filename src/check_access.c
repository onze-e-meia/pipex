/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:47:21 by tforster          #+#    #+#             */
/*   Updated: 2024/04/06 13:38:27 by tforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_null(void);
static int	check_dir(char *cmd);
static int	check_full_path(char *cmd);
static int	ck_paths(char **cmd, char **paths, char *cmd_name);

int	check_cmd_access(char **cmd, char **paths)
{
	char	*cmd_name;
	int		status;

	if (!cmd[0])
		return (check_null());
	status = check_dir(cmd[0]);
	if (status > 0)
		return (status);
	if (access(cmd[0], F_OK) == 0)
		return (check_full_path(cmd[0]));
	cmd_name = ft_strjoin("/", cmd[0]);
	status = ck_paths(cmd, paths, cmd_name);
	if (status >= 0)
		return (status);
	if (cmd_name)
		free(cmd_name);
	if (ft_strchr(*cmd, '/'))
		pf_printf(STDERR_FILENO, "%s: No such file or directory\n", cmd[0]);
	else
		pf_printf(STDERR_FILENO, "%s: Command not found\n", cmd[0]);
	return (127);
}

static int	check_null(void)
{
	pf_printf(STDERR_FILENO, " : Command not found\n");
	return (127);
}

static int	check_dir(char *cmd)
{
	int	fd;
	int	status;

	fd = open(cmd, __O_DIRECTORY);
	if (fd > 0)
	{
		if (ft_strchr(cmd, '/'))
		{
			pf_printf(STDERR_FILENO, "%s: Is a directory\n", cmd);
			status = 126;
		}
		else
		{
			pf_printf(STDERR_FILENO, "%s: Command not found\n", cmd);
			status = 127;
		}
		close(fd);
		return (status);
	}
	return (0);
}

static int	check_full_path(char *cmd)
{
	if (access(&cmd[0], X_OK) == 0)
		return (0);
	pf_printf(STDERR_FILENO, "%s: Permission denied\n", &cmd[0]);
	return (126);
}

static int	ck_paths(char **cmd, char **paths, char *cmd_name)
{
	int		status;
	char	*cmd_path;

	while (*paths && cmd[0][0] != '/' && cmd_name)
	{
		cmd_path = ft_strjoin(*paths, cmd_name);
		status = access(cmd_path, F_OK) + access(cmd_path, X_OK);
		if (cmd_path && status == 0)
		{
			free(cmd[0]);
			cmd[0] = cmd_path;
			free(cmd_name);
			return (0);
		}
		free(cmd_path);
		if (status == -1)
		{
			free(cmd_name);
			pf_printf(STDERR_FILENO, "%s: Permission denied\n", cmd[0]);
			return (127);
		}
		paths++;
	}
	return (-1);
}
