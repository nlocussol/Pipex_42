/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:08:12 by nlocusso          #+#    #+#             */
/*   Updated: 2022/10/03 21:20:01 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_iterative_power(long int nb, int power)
{
	long int	nb_temp;

	nb_temp = nb;
	if (power == 0 && nb == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		nb_temp = nb_temp * nb;
		power--;
	}
	return (nb_temp);
}
