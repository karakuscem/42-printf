/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42istanbul.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:36:23 by ckarakus          #+#    #+#             */
/*   Updated: 2022/12/28 15:57:16 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putconvert(size_t num, char *base)
{
	int			base_len;
	static char	converted[100];
	char		*to_return;

	base_len = ft_strlen(base);
	to_return = &converted[99];
	*to_return = '\0';
	*--to_return = base[num % base_len];
	num = num / base_len;
	while (num)
	{
		*--to_return = base[num % base_len];
		num = num / base_len;
	}
	return (ft_putstr(to_return));
}

void	ft_check(va_list args, char str, int *len)
{
	if (str == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (str == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
	{
		*len += ft_putstr("0x");
		*len += ft_putconvert(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (str == 'd' || str == 'i')
		*len += ft_putnumber(va_arg(args, int));
	else if (str == 'u')
		*len += ft_putconvert(va_arg(args, unsigned int), "0123456789");
	else if (str == 'x')
		*len += ft_putconvert(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		*len += ft_putconvert(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str == '%')
		*len += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		iter;
	int		len;

	va_start(args, str);
	iter = 0;
	len = 0;
	while (str[iter])
	{
		if (str[iter + 1] == '\0' && str[iter] == '%')
			ft_putchar(0);
		else if (str[iter] == '%')
		{
			ft_check(args, str[iter + 1], &len);
			iter++;
		}
		else
			len += write(1, &str[iter], 1);
		iter++;
	}
	va_end(args);
	return (len);
}
