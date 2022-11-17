/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:16 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/17 17:12:31 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_file(t_arg *arg)
{
	if (access(arg->first, R_OK) == -1 || open(arg->first, O_RDONLY) == -1)
		print_error(1, arg);
	if (open(arg->last, O_RDONLY) == -1)
		open(arg->last, O_CREAT);
	if (access(arg->last, W_OK) == -1)
		print_error(2, arg);
}
