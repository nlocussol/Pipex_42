/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:01:39 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/29 12:35:18 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void	*dest, const void *src, size_t size)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	str1 = (char *)dest;
	str2 = (char *)src;
	while (i < size)
	{
		str1[i] = str2[i];
		i++;
	}
	dest = (void *)str1;
	return (dest);
}
