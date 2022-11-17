/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:04:44 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 15:06:37 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**backslash_zero(char const *str)
{
	char	**tab;

	if (str[0] == '\0')
	{
		tab = malloc(sizeof(char *));
		if (tab == NULL)
			return (NULL);
		tab[0] = NULL;
	}
	else
	{
		tab = malloc(2 * sizeof(char *));
		if (tab == NULL)
			return (NULL);
		tab[0] = ft_strdup(str);
		if (tab[0] == NULL)
		{
			free(tab);
			return (NULL);
		}
		tab[1] = NULL;
	}
	return (tab);
}

static int	nb_word(char const *str, char charset)
{
	int	cnt;
	int	i;

	i = 1;
	cnt = 1;
	while (str[i - 1] == charset)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != charset && str[i - 1] == charset)
			cnt++;
		i++;
	}
	cnt++;
	return (cnt);
}

static int	length_malloc(char const *str, char charset, int i)
{
	int	i_tmp;

	i_tmp = i;
	while (str[i] != charset && str[i] != '\0')
		i++;
	return (i - i_tmp);
}

char	**ft_split(char const *str, char charset)
{
	int		i;
	int		x;
	char	**tab;

	i = 0;
	x = 0;
	if (str == NULL)
		return (NULL);
	if (*str == '\0' || charset == '\0')
		return (backslash_zero(str));
	tab = malloc(nb_word(str, charset) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == charset)
			i++;
		if (str[i] == '\0')
			break ;
		tab[x] = ft_substr(str, i, length_malloc(str, charset, i));
		i += length_malloc(str, charset, i);
		x++;
	}
	tab[x] = NULL;
	return (tab);
}
