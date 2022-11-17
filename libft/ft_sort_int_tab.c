/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:37:14 by nlocusso          #+#    #+#             */
/*   Updated: 2022/07/15 10:55:46 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	count2;
	int	count;

	count = 1;
	while (count != size)
	{
		count2 = count;
		while (count2 != 0 && tab[count2] < tab[count2 - 1])
		{
			temp = tab[count2];
			tab[count2] = tab[count2 - 1];
			tab[count2 - 1] = temp;
			count2--;
		}
		count++;
	}
}
