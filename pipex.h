/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:31 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/24 13:05:46 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}			t_cmd;

typedef struct s_arg
{
	int		nb_exe;
	int		path;
	char	*first;
	char	*last;
	char	**path_env;
	char	**env;
	int		*pid;
	int		*fd;
	int		exit;
	int		here_doc;
	char	*limiter;
	t_cmd	*nb_cmd;
}			t_arg;

void	ft_free_arg(t_arg *arg);
void	wait_pid(t_arg *arg, int i);
void	ft_close(int fd[2][2]);
void	check_fd(int fd);
void	exe_cmd(t_arg *arg);
void	split_path(t_arg *arg, char **envp);
void	ft_free(t_arg *arg);
void	fill_cmd(t_arg *arg, char **argv);
void	initialized_f(t_arg	*files, int argc, char **argv, char **env);
void	print_error(int error_type, t_arg *files, char *cmd);
void	access_file(t_arg *files);

#endif
