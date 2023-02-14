/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 05:53:11 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/17 15:56:09 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long nbr)
{
	int		read;
	char	*base;

	base = "0123456789abcdef";
	read = 0;
	if (nbr >= 16)
		read += ft_putptr(nbr / 16);
	read += write(1, &base[nbr % 16], 1);
	return (read);
}
