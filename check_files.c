/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:16 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/25 13:39:01 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_file(t_arg *arg)
{
	if ((access(arg->first, R_OK) == -1 || arg->fd[0] == -1)
		&& arg->here_doc != 1)
		print_error(1, arg, NULL);
	if (arg->here_doc == 1)
		arg->fd[1] = open(arg->last, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else if (arg->here_doc != 1)
		arg->fd[1] = open(arg->last, O_WRONLY | O_TRUNC | O_CREAT, 0644);
}
