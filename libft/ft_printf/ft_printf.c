/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <nlocusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:30:38 by nlocusso          #+#    #+#             */
/*   Updated: 2022/11/05 12:14:07 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fmt_check(const char *fmt, va_list args, int i, int cnt)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (fmt[i] == '%' && ft_strchr("csiduxXp", fmt[i + 1]) != NULL)
	{
		if (fmt[i + 1] == 'c')
			cnt = ft_putchar(va_arg(args, int), cnt);
		else if (fmt[i + 1] == 's')
			cnt = ft_putstr(va_arg(args, char *), cnt);
		else if (fmt[i + 1] == 'i')
			cnt = ft_putnbr(va_arg(args, int), cnt);
		else if (fmt[i + 1] == 'd')
			cnt = ft_putnbr(va_arg(args, int), cnt);
		else if (fmt[i + 1] == 'u')
			cnt = ft_putnbr_unsign(va_arg(args, int), cnt);
		else if (fmt[i + 1] == 'x')
			cnt = ft_putnbr_base(va_arg(args, int), hexa, cnt);
		else if (fmt[i + 1] == 'X')
			cnt = ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", cnt);
		else if (fmt[i + 1] == 'p')
			cnt = ft_putnbr_base_ptr(va_arg(args, unsigned long), hexa, cnt);
	}
	else
		cnt = ft_putchar(fmt[i], cnt);
	return (cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	size_t		i;
	int			cnt;

	i = 0;
	cnt = 0;
	if (!fmt)
		return (0);
	va_start(args, fmt);
	while (i != ft_strlen(fmt))
	{
		cnt = fmt_check(fmt, args, i, cnt);
		if (fmt[i] == '%' && ft_strchr("csiduxXp%", fmt[i + 1]) != NULL)
			i++;
		i++;
	}
	va_end(args);
	return (cnt);
}
