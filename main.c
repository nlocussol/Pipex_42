/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:19:52 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/24 16:14:11 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_pid(t_arg *arg, int i)
{
	int	cnt;
	int	status;

	cnt = 0;
	while (cnt != i)
	{
		if (arg->pid[cnt] != -1)
			waitpid(arg->pid[cnt], &status, 0);
		if (WIFEXITED(status))
			arg->exit = WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			arg->exit = WTERMSIG(status);
		cnt++;
	}
}

void	print_error(int error_type, t_arg *arg, char *cmd)
{
	char	*join;

	if (error_type == 0)
		ft_dprintf(2, "%s: command not found\n", cmd);
	if (error_type == 1)
	{
		arg->fd[0] = -1;
		join = ft_strjoin("bash: ", arg->first);
		perror(join);
		free(join);
		return ;
	}
	else if (error_type == 3)
		perror("bash");
	if (error_type == 4)
	{
		arg->fd[0] = -1;
		join = ft_strjoin("bash: ", arg->last);
		perror(join);
		free(join);
		ft_free_arg(arg);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_arg	*arg;
	int		exit_code;

	if (argc < 5)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	arg = malloc(sizeof(t_arg));
	arg->here_doc = 0;
	if (!ft_strcmp(argv[1], "here_doc"))
		arg->here_doc = 1;
	if (arg->here_doc == 1 && argc <= 5)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initialized_f(arg, argc, argv, env);
	access_file(arg);
	fill_cmd(arg, argv);
	split_path(arg, env);
	exe_cmd(arg);
	exit_code = arg->exit;
	ft_free(arg);
	return (exit_code);
}
