/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:30:55 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/25 14:00:22 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_error(t_arg *arg, t_cmd *cmd, int nb_cmd)
{
	if (nb_cmd == 0 && arg->here_doc == 1)
		print_error(0, arg, cmd->cmd[0]);
	else if (nb_cmd == 0 && access(arg->first, R_OK) != -1)
		print_error(0, arg, cmd->cmd[0]);
	else if (nb_cmd != 0 && nb_cmd != arg->nb_exe - 1)
		print_error(0, arg, cmd->cmd[0]);
	else if (nb_cmd == arg->nb_exe - 1 && access(arg->last, W_OK) != -1)
		print_error(0, arg, cmd->cmd[0]);
}

void	check_fd(int fd)
{
	if (fd != -1 && fd)
		close(fd);
}

void	ft_close(int fd[2][2], int here[2])
{
	check_fd(here[0]);
	check_fd(here[1]);
	check_fd(fd[0][0]);
	check_fd(fd[0][1]);
	check_fd(fd[1][0]);
	check_fd(fd[1][1]);
}
