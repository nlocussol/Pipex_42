/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:22:18 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/22 11:53:03 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

char	*ft_strchr(const char *str, int searchedChar);
long	ft_iterative_power(long int nb, int power);
int		ft_putchar(int fd, char c, int cnt);
int		ft_putnbr(int fd, int nb, int cnt);
int		ft_put_base(int fd, int nbr, char *base, int cnt);
int		ft_putnbr_ptr(int fd, unsigned long nbr, char *base, int cnt);
int		ft_putnbr_unsign(int fd, unsigned int nb, int cnt);
int		ft_putstr(int fd, char *str, int cnt);
size_t	ft_strlen(const char *str);
int		ft_dprintf(int fd, const char *fmt, ...);

#endif
