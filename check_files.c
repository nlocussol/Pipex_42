/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:16 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/18 15:39:04 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_file(t_arg *arg)
{
	if (access(arg->first, R_OK) == -1 || arg->fd1 == -1)
		print_error(1, arg);
	arg->fd2 = open(arg->last, O_WRONLY | O_TRUNC | O_CREAT, 0644);
}
