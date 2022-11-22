/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <nlocusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:30:38 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:37 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_check(int fd, const char *fmt, va_list args, int cnt)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (*fmt == '%' && ft_strchr("csiduxXp", *(fmt + 1)) != NULL)
	{
		if (*(fmt + 1) == 'c')
			cnt = ft_putchar(fd, va_arg(args, int), cnt);
		else if (*(fmt + 1) == 's')
			cnt = ft_putstr(fd, va_arg(args, char *), cnt);
		else if (*(fmt + 1) == 'i')
			cnt = ft_putnbr(fd, va_arg(args, int), cnt);
		else if (*(fmt + 1) == 'd')
			cnt = ft_putnbr(fd, va_arg(args, int), cnt);
		else if (*(fmt + 1) == 'u')
			cnt = ft_putnbr_unsign(fd, va_arg(args, int), cnt);
		else if (*(fmt + 1) == 'x')
			cnt = ft_put_base(fd, va_arg(args, int), hexa, cnt);
		else if (*(fmt + 1) == 'X')
			cnt = ft_put_base(fd, va_arg(args, int), "0123456789ABCDEF", cnt);
		else if (*(fmt + 1) == 'p')
			cnt = ft_putnbr_ptr(fd, va_arg(args, unsigned long), hexa, cnt);
	}
	else
		cnt = ft_putchar(fd, *fmt, cnt);
	return (cnt);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list		args;
	int			cnt;

	cnt = 0;
	if (!fmt)
		return (0);
	va_start(args, fmt);
	while (*fmt)
	{
		cnt = fmt_check(fd, fmt, args, cnt);
		if (*fmt == '%' && ft_strchr("csiduxXp%", *(fmt + 1)) != NULL)
			fmt++;
		fmt++;
	}
	va_end(args);
	return (cnt);
}
