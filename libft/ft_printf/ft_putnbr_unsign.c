/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:22:18 by nlocusso          #+#    #+#             */
/*   Updated: 2022/10/03 19:42:16 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_unsign(unsigned int nb, int cnt)
{
	unsigned int	nb_temp;

	nb_temp = nb + '0';
	if (nb <= 9)
	{
		write(1, &nb_temp, 1);
		cnt++;
	}
	if (nb > 9)
	{
		cnt = ft_putnbr_unsign(nb / 10, cnt);
		cnt = ft_putnbr_unsign(nb % 10, cnt);
	}
	return (cnt);
}
