/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:14:29 by ylachhab          #+#    #+#             */
/*   Updated: 2022/11/16 23:36:41 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_read(va_list str, char c);
int	ft_putchar(char c);
int	ft_putunsigned(unsigned int n);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_printhexa(unsigned int n);
int	ft_hexaup(unsigned int nb);
int	ft_putptr(unsigned long long n);

#endif
