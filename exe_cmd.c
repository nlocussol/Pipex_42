/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:02:02 by nlocusso          #+#    #+#             *//*   Updated: 2022/11/21 11:15:22 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int fd[2][2])
{
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
}

void	cmd_path(t_arg *arg, t_cmd *cmd)
{
	int		cnt;
	char	*tmp;

	cnt = 0;
	while (arg->path_env[cnt] != NULL)
	{
		tmp = ft_strjoin(arg->path_env[cnt], "/");
		cmd->path = ft_strjoin(tmp, cmd->cmd[0]);
		free(tmp);
		if (access(cmd->path, X_OK) == 0)
			return ;
		free(cmd->path);
		cnt++;
	}
	cmd->path = NULL;
	print_error(0, arg, cmd->cmd[0]);
}

void	exe_cmd(t_arg *arg, char **envp)
{
	int	cnt;
	int	status;
	int	i;
	int	fd[2][2];

	i = 0;
	cnt = 0;
	if (pipe(fd[0]) == -1)
		print_error(3, arg, NULL);
	if (pipe(fd[1]) == -1)
		print_error(3, arg, NULL);
	while (cnt != arg->nb_exe)
	{
		if (cnt >= 2)
		{
			close(fd[cnt % 2][0]);
			close(fd[cnt % 2][1]);
			if (pipe(fd[cnt % 2]) == -1)
				print_error(3, arg, NULL);
		}
		cmd_path(arg, &arg->nb_cmd[cnt]);
		if (arg->nb_cmd[cnt].path != NULL)
		{
			arg->pid[i] = fork();
			if (arg->pid[i] < 0)
				print_error(3, arg, NULL);
			else if (arg->pid[i] == 0)
			{
				if (cnt == 0)
				{
					if (arg->fd[0] == -1)
						exit(EXIT_FAILURE);
					dup2(arg->fd[0], 0);
					dup2(fd[0][1], 1);
				}
				else if (cnt == arg->nb_exe - 1)
				{
					dup2(fd[(cnt + 1) % 2][0], 0);
					dup2(arg->fd[1], 1);
				}
				else
				{
					dup2(fd[(cnt + 1) % 2][0], 0);
					dup2(fd[cnt % 2][1], 1);
				}
				ft_close(fd);
				execve(arg->nb_cmd[cnt].path, arg->nb_cmd[cnt].cmd, envp);
				exit(EXIT_FAILURE);
			}
		}
		else
			arg->pid[i] = -1;
		i++;
		cnt++;
	}
	cnt = 0;
	ft_close(fd);
	while (cnt != i)
	{
		if (arg->pid[cnt] != -1)
			waitpid(arg->pid[cnt], &status, 0);
		cnt++;
	}
	close(arg->fd[0]);
	close(arg->fd[1]);
}
