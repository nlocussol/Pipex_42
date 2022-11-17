/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:46:40 by nlocusso          #+#    #+#             */
/*   Updated: 2022/10/03 12:19:06 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	len_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

static void	ft_putnbr_base_bis(long int nb, char *base)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb *(-1);
	}
	if (nb >= 0 && nb < len_base(base))
		write(1, &base[nb % len_base(base)], 1);
	if (nb > len_base(base) - 1)
	{
		ft_putnbr_base_bis(nb / len_base(base), base);
		ft_putnbr_base_bis(nb % len_base(base), base);
	}
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

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nbr_long;

	nbr_long = nbr;
	if (conditions((unsigned char *)base) == 1)
		ft_putnbr_base_bis(nbr_long, base);
}
