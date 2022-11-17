/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialized.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:14:57 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/17 19:49:51 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialized_f(t_arg *arg, int argc, char **argv)
{
	arg->path = 0;
	arg->nb_exe = argc - 3;
	arg->first = argv[1];
	arg->last = argv[argc - 1];
	arg->pid = malloc(arg->nb_exe * sizeof(int));
	arg->nb_cmd = malloc((argc - 2) * sizeof(t_cmd));
}
