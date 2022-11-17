/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:20:39 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/17 19:08:50 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char	**str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free(t_arg *arg)
{
	int	cnt;

	cnt = 0;
	while (cnt != arg->nb_exe)
	{
		if (arg->nb_cmd[cnt].cmd != NULL)
			free_split(arg->nb_cmd[cnt].cmd);
		if (arg->nb_cmd[cnt].path != NULL)
			free(arg->nb_cmd[cnt].path);
		cnt++;
	}
	free(arg->pid);
	free_split(arg->path_env);
	free(arg->nb_cmd);
	free(arg);
}
