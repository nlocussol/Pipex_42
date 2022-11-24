/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:22:18 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/24 16:21:12 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr(int fd, int nb, int cnt)
{
	int	nb_temp;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (cnt + 11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		cnt++;
		nb = nb *(-1);
	}
	nb_temp = nb + '0';
	if (nb >= 0 && nb <= 9)
	{
		write(1, &nb_temp, 1);
		cnt++;
	}
	if (nb > 9)
	{
		cnt = ft_putnbr(fd, nb / 10, cnt);
		cnt = ft_putnbr(fd, nb % 10, cnt);
	}
	return (cnt);
}
