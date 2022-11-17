/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:39:31 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 14:58:53 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	in_str(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static size_t	empty_test(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (in_str(s1[i], set) == 1)
	{
		if (i == ft_strlen(s1) - 1)
			return (1);
		i++;
	}
	return (0);
}

static size_t	delend(char const *s1, char const *set)
{
	int	count;
	int	len;

	len = ft_strlen(s1) - 1;
	count = 0;
	while (in_str(s1[len], set) == 1)
	{
		len--;
		count++;
	}
	return (count);
}

static size_t	delbeg(char const *s1, char const *set)
{
	int	count;

	count = 0;
	while (in_str(s1[count], set) == 1)
		count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (s1 == NULL)
		return (NULL);
	if (empty_test(s1, set) == 1)
	{
		new_str = malloc(1);
		if (new_str != NULL)
			new_str[0] = '\0';
		return (new_str);
	}
	new_str = malloc(ft_strlen(s1) - delbeg(s1, set) - delend(s1, set) + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < delbeg(s1, set))
		i++;
	while (y != ft_strlen(s1) - delbeg(s1, set) - delend(s1, set))
		new_str[y++] = s1[i++];
	new_str[y] = '\0';
	return (new_str);
}
