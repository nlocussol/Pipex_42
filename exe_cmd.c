/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:19:26 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/27 15:34:49 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_path(t_arg *arg, t_cmd *cmd, int nb_cmd)
{
	int		cnt;
	char	*tmp;

	cnt = 0;
	while (arg->path_env[cnt] != NULL)
	{
		if (access(cmd->cmd[0], X_OK) == 0)
		{
			cmd->path = ft_strdup(cmd->cmd[0]);
			return ;
		}
		tmp = ft_strjoin(arg->path_env[cnt], "/");
		cmd->path = ft_strjoin(tmp, cmd->cmd[0]);
		free(tmp);
		if (access(cmd->path, X_OK) == 0)
			return ;
		free(cmd->path);
		cnt++;
	}
	cmd->path = NULL;
	arg->exit = 127;
	put_error(arg, cmd, nb_cmd);
}

void	here_doc(t_arg *arg, int here_pipe[2])
{
	char	*line;

	if (arg->here_doc == 1)
	{
		ft_dprintf(1, "> ");
		line = get_next_line(0);
		ft_putstr_fd(line, here_pipe[1]);
		line[ft_strlen(line) - 1] = 0;
		while (ft_strcmp(line, arg->limiter))
		{
			free(line);
			ft_dprintf(1, "> ");
			line = get_next_line(0);
			if (ft_strncmp(line, arg->limiter, ft_strlen(line) - 1))
				ft_putstr_fd(line, here_pipe[1]);
			line[ft_strlen(line) - 1] = 0;
		}
		free(line);
		arg->fd[0] = here_pipe[0];
	}
}

void	child_program(int cnt, t_arg *arg, int fd[2][2], int here_pipe[2])
{
	if (cnt == 0)
	{
		if (arg->cmd != 1 && arg->fd[0] == -1)
		{
			ft_close(fd, here_pipe);
			ft_free(arg);
			exit(EXIT_FAILURE);
		}
		if (arg->cmd != 1)
			dup2(arg->fd[0], 0);
		if (arg->nb_exe != 1)
			dup2(fd[0][1], 1);
	}
	else if (cnt == arg->nb_exe - 1)
	{
		dup2(fd[(cnt + 1) % 2][0], 0);
		if (arg->cmd != 1)
			dup2(arg->fd[1], 1);
	}
	else
	{
		dup2(fd[(cnt + 1) % 2][0], 0);
		dup2(fd[cnt % 2][1], 1);
	}
	ft_close(fd, here_pipe);
	execve(arg->nb_cmd[cnt].path, arg->nb_cmd[cnt].cmd, arg->env);
	exit(EXIT_FAILURE);
}

void	create_pipe(t_arg *arg, int cnt, int fd[2][2], int here_pipe[2])
{
	if (arg->cmd == 0 && cnt == arg->nb_exe - 1
		&& access(arg->last, W_OK) == -1)
	{
		print_error(4, arg, NULL);
		return ;
	}
	if (cnt >= 2)
	{
		close(fd[cnt % 2][0]);
		close(fd[cnt % 2][1]);
		if (pipe(fd[cnt % 2]) == -1)
			print_error(3, arg, NULL);
	}
	cmd_path(arg, &arg->nb_cmd[cnt], cnt);
	if (arg->nb_cmd[cnt].path != NULL)
	{
		arg->pid[cnt] = fork();
		if (arg->pid[cnt] < 0)
			print_error(3, arg, NULL);
		else if (arg->pid[cnt] == 0)
			child_program(cnt, arg, fd, here_pipe);
	}
	else
		arg->pid[cnt] = -1;
}

void	exe_cmd(t_arg *arg, int fd[2][2], int here_pipe[2])
{
	int	cnt;

	cnt = 0;
	while (cnt != arg->nb_exe)
	{
		create_pipe(arg, cnt, fd, here_pipe);
		if (arg->nb_cmd[cnt].path == NULL && cnt == arg->nb_exe - 1)
			return ;
		cnt++;
	}
	ft_close(fd, here_pipe);
	wait_pid(arg, cnt);
	check_fd(arg->fd[0]);
	check_fd(arg->fd[1]);
}
