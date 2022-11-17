/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:03:25 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/14 15:03:34 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_extension(char *str, char *extension)
{
	int	i;

	i = ft_strlen(str);
	i -= ft_strlen(extension);
	if (str[i - 1] == '/')
		return (1);
	if (ft_strcmp(&str[ft_strlen(str) - ft_strlen(extension)], extension))
		return (1);
	return (0);
}
