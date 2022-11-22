/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:46:40 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/22 11:58:02 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static unsigned long	len_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

static int	ft_putnbr_base_bis(int fd, unsigned long nb, char *base, int cnt)
{
	if (nb < len_base(base))
	{
		write(fd, &base[nb % len_base(base)], 1);
		cnt++;
	}
	if (nb > len_base(base) - 1)
	{
		cnt = ft_putnbr_base_bis(fd, nb / len_base(base), base, cnt);
		cnt = ft_putnbr_base_bis(fd, nb % len_base(base), base, cnt);
	}
	return (cnt);
}

static int	conditions(unsigned char *base)
{
	int		i;
	int		tab[256];

	i = 0;
	while (i++ < 256)
		tab[i] = 0;
	i = 0;
	if (len_base((char *)base) == 1 || len_base((char *)base) == 0)
		return (0);
	while (base[i] != '\0')
	{
		if (tab[base[i]] == 1)
			return (0);
		else
			tab[base[i]] = 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_putnbr_ptr(int fd, unsigned long nbr, char *base, int cnt)
{
	unsigned long	nbr_long;

	if ((void *)nbr == NULL)
	{
		cnt = ft_putstr(fd, "(nil)", cnt);
		return (cnt);
	}
	write(1, "0x", 2);
	cnt += 2;
	nbr_long = nbr;
	if (conditions((unsigned char *)base) == 1)
		cnt = ft_putnbr_base_bis(fd, nbr_long, base, cnt);
	return (cnt);
}
