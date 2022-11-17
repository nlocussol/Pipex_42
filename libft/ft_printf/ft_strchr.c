/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:46:54 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/27 14:02:04 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int searchedChar)
{
	int	i;

	i = 0;
	while (searchedChar > 255)
		searchedChar -= 256;
	while (str[i] != '\0')
	{
		if (str[i] == searchedChar)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == searchedChar)
		return ((char *)str + i);
	return (NULL);
}
