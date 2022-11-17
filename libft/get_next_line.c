/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:02:16 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/04 14:35:54 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new_str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		if (s1[i] == '\n')
			return (new_str);
		i++;
	}
	while (s2[j] != '\0')
	{
		new_str[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*fill_line(char *str)
{
	int			j;
	int			i;
	char		*new_str;

	j = 1;
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[j - 1] != '\n' && str[j] != '\0')
		j++;
	while (str[j] != '\0')
	{
		str[i] = str[j];
		i++;
		j++;
	}
	while (i < j)
	{
		str[i] = 0;
		i++;
	}
	new_str = ft_strdup(str);
	return (new_str);
}

static int	check_read_size(char *str, int read_file)
{
	if (read_file == 0 && str[0] == '\0')
		return (1);
	else if (read_file < 0)
		return (1);
	else
		return (0);
}

static char	*recursive_read(char *str, char *line, int fd)
{
	int		read_file;
	int		cnt;
	char	*tmp;

	if (ft_strchr(str, '\n') == NULL)
	{
		read_file = read(fd, str, BUFFER_SIZE);
		str[read_file] = '\0';
		if (check_read_size(str, read_file) == 1 && line[0] == '\0')
		{
			free(line);
			return (NULL);
		}
	}
	tmp = ft_strjoin_gnl(line, str);
	free(line);
	if (tmp == NULL)
		return (NULL);
	line = tmp;
	cnt = 0;
	while (str[cnt] != '\n' && str[cnt] != '\0' && cnt < BUFFER_SIZE)
		cnt++;
	if (str[cnt] == '\n' || read_file < BUFFER_SIZE)
		return (line);
	return (recursive_read(str, line, fd));
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*line;

	line = fill_line(str);
	line = recursive_read(str, line, fd);
	return (line);
}
