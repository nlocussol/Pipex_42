/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:21:09 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 01:22:37 by nlocusso         ###   ########.fr       */
/*   Updated: 2022/09/27 15:54:54 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	size_t	len_minus_i;

	i = 0;
	len_little = ft_strlen(little);
	if (len_little == 0 || (big == little && len_little <= len))
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && i < len && len_little <= len - i)
	{
		len_minus_i = len - i;
		if (len_little < len - i)
			len_minus_i = len_little;
		if (ft_strncmp(big + i, little, len_minus_i) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
