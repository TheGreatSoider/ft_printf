/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:43 by cocheong          #+#    #+#             */
/*   Updated: 2022/10/11 14:58:11 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print;

	print = 0;
	if (format == 'c')
		print += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print += write(1, "%", 1);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
