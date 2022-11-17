/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:31:30 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/29 10:48:08 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	nb_temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ((void) 0);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n *(-1);
	}
	nb_temp = n + '0';
	if (n >= 0 && n <= 9)
		write(fd, &nb_temp, 1);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
