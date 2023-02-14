/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:55:18 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/16 21:49:38 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	long	nb;
	char	c;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		i++;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	if (nb <= 9)
	{
		c = nb + 48;
		i += write(1, &c, 1);
	}
	return (i);
}
