/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:02:02 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/18 16:12:46 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	print_error(3, arg);
}

void	exe_cmd(t_arg *arg, char **envp)
{
	int	cnt;
	int	status;
	int	i;
	int	fd[2];

	i = 0;
	cnt = 0;
	if (pipe(fd) == -1)
		print_error(3, arg);
	while (cnt != arg->nb_exe)
	{
		cmd_path(arg, &arg->nb_cmd[cnt]);
		if (arg->nb_cmd[cnt].path != NULL)
		{
			arg->pid[i] = fork();
			if (arg->pid[i] < 0)
				print_error(3, arg);
			else if (arg->pid[i] == 0)
			{
				if (cnt == 0)
				{
					dup2(arg->fd1, 0);
					dup2(fd[1], 1);
				}
				else if (cnt == arg->nb_exe - 1)
				{
					dup2(fd[0], 0);
					dup2(arg->fd2, 1);
				}
				else
				{
					dup2(fd[0], 0);
					dup2(fd[1], 1);
				}
				close(fd[0]);
				close(fd[1]);
				execve(arg->nb_cmd[cnt].path, arg->nb_cmd[cnt].cmd, envp);
				exit(EXIT_FAILURE);
			}
			//usleep(10000);
		}
		else
			arg->pid[i] = -1;
		i++;
		cnt++;
	}
	cnt = 0;
	close(fd[0]);
	close(fd[1]);
	while (cnt != i)
	{
		if (arg->pid[cnt] != -1)
			waitpid(arg->pid[cnt], &status, 0);
		cnt++;
	}
}
