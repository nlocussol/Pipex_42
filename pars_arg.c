/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:08:50 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/22 14:32:13 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fill_cmd(t_arg *arg, char **argv)
{
	int	cnt;

	cnt = 0;
	while (cnt != arg->nb_exe)
	{
		if (arg->here_doc != 1)
			arg->nb_cmd[cnt].cmd = ft_split(argv[cnt + 2], ' ');
		else
			arg->nb_cmd[cnt].cmd = ft_split(argv[cnt + 3], ' ');
		cnt++;
	}
}

void	find_path(t_arg *arg, char **envp)
{
	int	cnt;

	cnt = 0;
	while (envp[cnt] != NULL)
	{
		if (ft_strncmp(envp[cnt], "PATH", 4) == 0)
		{
			arg->path = cnt;
			return ;
		}
		cnt++;
	}
}

void	split_path(t_arg *arg, char **envp)
{
	char	*path;

	find_path(arg, envp);
	path = ft_strchr(envp[arg->path], '/');
	arg->path_env = ft_split(path, ':');
}
