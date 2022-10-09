/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:11:46 by cocheong          #+#    #+#             */
/*   Updated: 2022/10/08 22:11:46 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		write (1, '("null")', 6);
		return (0);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	printptr;

	printptr = 0;
	printptr += write(1, "0x", 2);
	if (ptr == 0)
		printptr += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		printptr += ft_ptrlength(ptr);
	}
	return (printptr);
}

int	ft_putnbr(int n)
{
	int		i;
	char	*nbr;

	nbr = ft_itoa(n);
	i = ft_putstr(nbr);
	free (nbr);
	return (i);
}

int	ft_print_unsigned(unsigned int n)
{
	int		uprint;
	char	*num;

	uprint = 0;
	if (n == 0)
		uprint += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		uprint += ft_putstr(num);
		free(num);
	}
	return (uprint);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, format);
	return (ft_hexlength(n));
}
