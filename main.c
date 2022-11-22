/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:19:52 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/22 14:37:31 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(int error_type, t_arg *arg, char *cmd)
{
	char	*join;

	if (error_type == 0)
		ft_dprintf(2, "bash : command not found : %s\n", cmd);
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
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	*arg;
	char	*line;

	if (argc < 5 && ft_strcmp(argv[1], "here_doc"))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	arg = malloc(sizeof(t_arg));
	if (!ft_strcmp(argv[1], "here_doc"))
		arg->here_doc = 1;
	else if (arg->here_doc == 1 && argc <= 5)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initialized_f(arg, argc, argv);
	access_file(arg);
	fill_cmd(arg, argv);
	split_path(arg, envp);
	exe_cmd(arg, envp);
	if (arg->here_doc == 1)
	{
		line = get_next_line(0);
		line[ft_strlen(line) - 1] = 0;
		while (ft_strcmp(line, arg->limiter))
		{
			free(line);
			line = get_next_line(0);
			line[ft_strlen(line) - 1] = 0;
		}
		free(line);
	}
	ft_free(arg);
	return (0);
}
