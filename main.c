/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:19:52 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/21 20:36:30 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(int error_type, t_arg *arg, char *cmd)
{
	char	*join;

	(void)cmd;	
	if (error_type == 0)
	//ft_fd_printf
		write(2, "bash : command not found", 24);
	if (error_type == 1)
	{
		arg->fd[0] = -1;
		join = ft_strjoin("bash : ", arg->first);
		perror(join);
		free(join);
		return ;
	}
	else if (error_type == 2)
	{
		join = ft_strjoin("bash : ", arg->last);
		perror(join);
		free(join);
	}
	else if (error_type == 3)
		perror("bash ");
	//ft_free(arg);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	*arg;

	if (argc < 5)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	arg = malloc(sizeof(t_arg));
	initialized_f(arg, argc, argv);
	access_file(arg);
	fill_cmd(arg, argv);
	split_path(arg, envp);
	exe_cmd(arg, envp);
	ft_free(arg);
	return (0);
}
