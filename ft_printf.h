/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cocheong <cocheong@student.42kl.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:30:53 by cocheong          #+#    #+#             */
/*   Updated: 2022/10/03 23:30:53 by cocheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>
# include <stdint.h>

int		ft_printchar(int c);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
char	ft_uitoa(unsigned int n);
int		length(unsigned int n);
void	ft_puthex(unsigned int n, const char format);
int		hexlength(unsigned int n);
void	ft_putptr(unsigned long long n);
int		ft_ptrlength(unsigned long long n);

#endif