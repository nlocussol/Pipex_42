/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:37:37 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 00:41:12 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new_str = ft_strdup(s);
	if (new_str == NULL)
		return (NULL);
	while (new_str[i] != '\0')
	{
		new_str[i] = f(i, new_str[i]);
		i++;
	}
	return (new_str);
}
