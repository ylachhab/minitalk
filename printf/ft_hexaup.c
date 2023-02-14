/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 05:52:32 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/17 15:49:34 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaup(unsigned int n)
{
	char	*base;
	char	c;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (n < 16)
	{
		c = base[n];
		i += write (1, &c, 1);
	}
	else
	{
		i += ft_hexaup(n / 16);
		i += ft_hexaup(n % 16);
	}
	return (i);
}
