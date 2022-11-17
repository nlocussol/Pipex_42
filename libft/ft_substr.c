/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:41:22 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 13:13:52 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	int		size_malloc;

	if (s == NULL)
		return (NULL);
	size_malloc = ft_strlen(s);
	size_malloc -= start;
	if (size_malloc < 0)
		size_malloc = 0;
	if ((size_t)size_malloc > len)
		size_malloc = len;
	new_str = malloc(size_malloc + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[size_malloc] = '\0';
	while (size_malloc-- > 0)
		new_str[size_malloc] = s[start + size_malloc];
	return (new_str);
}
