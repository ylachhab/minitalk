/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:11:53 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/17 16:04:11 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	char	*s;
	int		ret;
	int		i;

	if (write(1, NULL, 0) == -1)
		return (-1);
	va_start(ptr, str);
	s = (char *)str;
	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				break ;
			ret += ft_read(ptr, s[i]);
		}
		else
			ret += ft_putchar(s[i]);
		i++;
	}
	return (va_end(ptr), ret);
}
