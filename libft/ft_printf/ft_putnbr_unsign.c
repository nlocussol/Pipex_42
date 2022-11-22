/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:22:18 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/22 11:45:10 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsign(int fd, unsigned int nb, int cnt)
{
	unsigned int	nb_temp;

	nb_temp = nb + '0';
	if (nb <= 9)
	{
		write(fd, &nb_temp, 1);
		cnt++;
	}
	if (nb > 9)
	{
		cnt = ft_putnbr_unsign(fd, nb / 10, cnt);
		cnt = ft_putnbr_unsign(fd, nb % 10, cnt);
	}
	return (cnt);
}
