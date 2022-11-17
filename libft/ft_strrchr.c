/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:54:31 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/28 09:50:39 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	int	i;

	i = ft_strlen(str);
	if (searchedChar > 255)
		searchedChar -= 256;
	while (i != 0)
	{
		if (str[i] == searchedChar)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == searchedChar)
		return ((char *)str + i);
	return (NULL);
}
