/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:57:55 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/17 10:13:09 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned int n)
{
	char	*base;
	char	c;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		c = base[n];
		i += write (1, &c, 1);
	}
	else
	{
		i += ft_printhexa(n / 16);
		i += ft_printhexa(n % 16);
	}
	return (i);
}
