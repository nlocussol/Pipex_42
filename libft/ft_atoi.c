/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:49:04 by nlocusso          #+#    #+#             */
/*   Updated: 2022/10/18 11:33:35 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

t_overflow	ft_atoi(const char *str)
{
	int			i;
	t_overflow	nb;
	int			sign;

	sign = 1;
	nb.atoi = 0;
	nb.check = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb.atoi = nb.atoi * 10 + (str[i] - 48) * sign;
		if (nb.atoi > INT_MAX || nb.atoi < INT_MIN)
			nb.check = 1;
		i++;
	}
	return (nb);
}
