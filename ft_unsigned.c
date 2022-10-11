/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:06:34 by cocheong          #+#    #+#             */
/*   Updated: 2022/10/11 15:22:30 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	length(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = (n / 10);
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = length(n);
	num = ft_calloc(sizeof(char), len + 1);
	if (num == NULL)
		return (NULL);
	num[len--] = '\0';
	while (n > 0)
	{
		num[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (num);
}
