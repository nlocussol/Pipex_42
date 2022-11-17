/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:37:21 by nlocusso          #+#    #+#             */
/*   Updated: 2022/09/30 14:58:17 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	len_malloc(long int n, int sign)
{
	int	cnt;

	cnt = 0;
	while (n >= 10)
	{
		n = n / 10;
		cnt++;
	}
	if (sign == 1)
		cnt++;
	return (cnt);
}

static void	*ft_itoa_bis(long n_long, int sign)
{
	int			length;
	char		*convert;
	long		nb_tmp;

	length = len_malloc(n_long, sign) + 1;
	convert = malloc(length + 1);
	if (convert == NULL)
		return (NULL);
	convert[length] = '\0';
	convert[0] = sign * 45;
	while (n_long >= 10)
	{
		nb_tmp = n_long;
		convert[length - 1] = nb_tmp % 10 + '0';
		n_long /= 10;
		length--;
	}
	convert[length - 1] = n_long + '0';
	return (convert);
}

char	*ft_itoa(int n)
{
	long		n_long;
	int			i;
	int			sign;

	n_long = n;
	i = 0;
	sign = 0;
	if (n_long < 0)
	{
		sign = 1;
		n_long *= -1;
		i++;
	}
	return (ft_itoa_bis(n_long, sign));
}
