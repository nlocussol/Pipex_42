/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:13:03 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 17:47:07 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*str_dest;
	const char	*str_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	str_src = (const char *)src;
	str_dest = (char *)dest;
	if (src < dest)
	{
		size++;
		while (--size)
			*(str_dest + size - 1) = *(str_src + size - 1);
	}
	else
		dest = ft_memcpy(str_dest, str_src, size);
	dest = (void *)str_dest;
	return (dest);
}
