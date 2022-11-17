/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:44:21 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/27 12:34:14 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *pt, int value, size_t count)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)pt;
	while (i != count)
	{
		str[i] = value;
		i++;
	}
	pt = (void *)str;
	return (pt);
}
