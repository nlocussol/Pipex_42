/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialized.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:14:57 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/25 13:53:27 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initialized_f(t_arg *arg, int argc, char **argv, char **env)
{
	arg->path = 0;
	arg->first = argv[1];
	arg->last = argv[argc - 1];
	arg->fd = malloc(2 * sizeof(int));
	arg->env = env;
	arg->exit = 0;
	if (arg->env[0] == NULL || arg->env[0][0] == '\0')
		arg->exit = 127;
	if (arg->here_doc == 1)
	{
		arg->nb_exe = argc - 4;
		arg->limiter = argv[2];
		arg->pid = ft_calloc(arg->nb_exe, sizeof(int));
		arg->nb_cmd = ft_calloc(argc - 2, sizeof(t_cmd));
		arg->fd[0] = 0;
	}
	else
	{
		arg->nb_exe = argc - 3;
		arg->pid = ft_calloc(arg->nb_exe, sizeof(int));
		arg->nb_cmd = ft_calloc(argc - 2, sizeof(t_cmd));
		arg->fd[0] = open(argv[1], O_RDONLY);
	}
}

void	initialized_pipe(t_arg *arg)
{
	int		i;
	int		fd[2][2];
	int		here_pipe[2];

	i = 0;
	if (arg->here_doc == 1)
	{
		if (pipe(here_pipe) == -1)
			print_error(3, arg, NULL);
	}
	else
	{
		here_pipe[0] = 0;
		here_pipe[1] = 0;
	}
	if (pipe(fd[0]) == -1)
		print_error(3, arg, NULL);
	if (pipe(fd[1]) == -1)
		print_error(3, arg, NULL);
	here_doc(arg, here_pipe);
	exe_cmd(arg, fd, here_pipe);
}
