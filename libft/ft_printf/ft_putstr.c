/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:55:48 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/22 11:46:37 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(int fd, char *str, int cnt)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr(fd, "(null)", cnt));
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		cnt++;
		i++;
	}
	return (cnt);
}
