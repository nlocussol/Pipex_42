/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:46:40 by nlocusso          #+#    #+#             */
/*   Updated: 2022/10/03 21:22:02 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	len_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

static int	ft_putnbr_base_bis(long int nb, char *base, int cnt)
{
	if (nb < 0)
		nb = ft_iterative_power(len_base(base), 8) + nb;
	if (nb >= 0 && nb < len_base(base))
	{
		cnt++;
		write(1, &base[nb % len_base(base)], 1);
	}
	if (nb > len_base(base) - 1)
	{
		cnt = ft_putnbr_base_bis(nb / len_base(base), base, cnt);
		cnt = ft_putnbr_base_bis(nb % len_base(base), base, cnt);
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

int	ft_putnbr_base(int nbr, char *base, int cnt)
{
	long int	nbr_long;

	nbr_long = nbr;
	if (conditions((unsigned char *)base) == 1)
		cnt = ft_putnbr_base_bis(nbr_long, base, cnt);
	return (cnt);
}
