/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:56:26 by ylachhab          #+#    #+#             */
/*   Updated: 2023/01/13 15:01:13 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
int		ft_putchar(char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		convert_decimal(char *str);
void	ft_server_handler(int signal, siginfo_t *sa, void *d);
void	ft_client(char c, pid_t pid);

#endif