/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:02:23 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/27 18:01:46 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *mem, int SearchedChar, size_t size)
{
	size_t	i;
	char	*str_mem;

	str_mem = (char *)mem;
	i = 0;
	while (SearchedChar > 255)
		SearchedChar -= 256;
	while (i < size)
	{
		if (str_mem[i] == SearchedChar)
			return ((void *)mem + i);
		i++;
	}
	return (NULL);
}
