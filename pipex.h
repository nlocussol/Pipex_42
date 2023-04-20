/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:31 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/27 14:48:10 by nlocusso         ###   ########.fr       */
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
	int		cmd;
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

void	put_error(t_arg *arg, t_cmd *cmd, int nb_cmd);
void	exe_cmd(t_arg *arg, int fd[2][2], int here_pipe[2]);
void	here_doc(t_arg *arg, int here_pipe[2]);
void	ft_free_arg(t_arg *arg);
void	wait_pid(t_arg *arg, int i);
void	ft_close(int fd[2][2], int here[2]);
void	check_fd(int fd);
void	initialized_pipe(t_arg *arg);
void	split_path(t_arg *arg, char **envp);
void	ft_free(t_arg *arg);
void	fill_cmd(t_arg *arg, char **argv);
void	initialized_f(t_arg	*files, int argc, char **argv, char **env);
void	print_error(int error_type, t_arg *files, char *cmd);
void	access_file(t_arg *files);

#endif
