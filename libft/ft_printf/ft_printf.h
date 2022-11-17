/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:22:18 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/05 12:14:18 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

char	*ft_strchr(const char *str, int searchedChar);
long	ft_iterative_power(long int nb, int power);
int		ft_putchar(char c, int cnt);
int		ft_putnbr(int nb, int cnt);
int		ft_putnbr_base(int nbr, char *base, int cnt);
int		ft_putnbr_base_ptr(unsigned long nbr, char *base, int cnt);
int		ft_putnbr_unsign(unsigned int nb, int cnt);
int		ft_putstr(char *str, int cnt);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *fmt, ...);

#endif
