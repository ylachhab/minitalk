/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:56:29 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/16 01:32:28 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	c;
	int		i;

	i = 0;
	if (n <= 9)
	{
		c = n + 48;
		i += write(1, &c, 1);
	}
	if (n > 9)
	{
		i += ft_putunsigned(n / 10);
		i += ft_putunsigned(n % 10);
	}
	return (i);
}
