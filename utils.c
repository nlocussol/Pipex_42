/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:30:55 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/25 11:02:50 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
