/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:19:52 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/18 15:32:01 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(int error_type, t_arg *arg)
{
	char	*join;

	if (error_type == 0)
		ft_printf("Error\nUsage : ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
	else if (error_type == 1)
	{
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
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	initialized_f(arg, argc, argv);
	if (argc < 5)
	{
		print_error(0, arg);
		exit(EXIT_FAILURE);
	}
	access_file(arg);
	fill_cmd(arg, argv);
	split_path(arg, envp);
	exe_cmd(arg, envp);
	ft_free(arg);
	return (0);
}
