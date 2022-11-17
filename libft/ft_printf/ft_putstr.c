/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:55:48 by nlocusso          #+#    #+#             */
/*   Updated: 2022/10/04 10:28:19 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *str, int cnt)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)", cnt));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		cnt++;
		i++;
	}
	return (cnt);
}
