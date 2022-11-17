/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:37:37 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 15:10:39 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	cnt_dest;
	unsigned int	cnt_src;

	cnt_dest = 0;
	cnt_src = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (dest == NULL && !size)
		return (0);
	while (src[cnt_src] != '\0')
		cnt_src++;
	while (dest[cnt_dest] != '\0' && cnt_dest < size)
		cnt_dest++;
	if (dest[cnt_dest] != '\0')
		return (cnt_src + cnt_dest);
	while (src[i] != '\0' && cnt_dest + i < size - 1)
	{
		dest[cnt_dest + i] = src[i];
		i++;
	}
	dest[cnt_dest + i] = '\0';
	return (cnt_dest + cnt_src);
}
