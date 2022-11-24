/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:20:39 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/24 11:48:23 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_split(char	**str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		check_free(str[i]);
		i++;
	}
	check_free(str);
}

void	ft_free_arg(t_arg *arg)
{
	check_free(arg->fd);
	check_free(arg->pid);
	check_free(arg->nb_cmd);
	check_free(arg);
}

void	ft_free(t_arg *arg)
{
	int	cnt;

	cnt = 0;
	while (cnt != arg->nb_exe && arg->nb_cmd != NULL)
	{
		if (arg->nb_cmd[cnt].cmd != NULL)
			free_split(arg->nb_cmd[cnt].cmd);
		if (arg->nb_cmd[cnt].path != NULL)
			check_free(arg->nb_cmd[cnt].path);
		cnt++;
	}
	check_free(arg->pid);
	check_free(arg->fd);
	free_split(arg->path_env);
	check_free(arg->nb_cmd);
	check_free(arg);
}
