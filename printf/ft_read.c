/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:37:38 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/17 15:57:05 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read(va_list str, char c)
{
	int	form;

	form = 0;
	if (c == '%')
		form += ft_putchar('%');
	else if (c == 'c')
		form += ft_putchar(va_arg(str, int));
	else if (c == 'i' || c == 'd')
		form += ft_putnbr(va_arg(str, int));
	else if (c == 's')
		form += ft_putstr(va_arg(str, char *));
	else if (c == 'u')
		form += ft_putunsigned(va_arg(str, unsigned int));
	else if (c == 'p')
	{
		form += write(1, "0x", 2);
		form += ft_putptr(va_arg(str, unsigned long long));
	}
	else if (c == 'x')
		form += ft_printhexa(va_arg(str, unsigned int));
	else if (c == 'X')
		form += ft_hexaup(va_arg(str, unsigned int));
	return (form);
}
