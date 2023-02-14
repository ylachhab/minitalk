/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:41:45 by ylachhab          #+#    #+#             */
/*   Updated: 2023/01/07 19:18:09 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
int		ft_putchar(char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_convert_decimal(char *str, pid_t si_pid);
void	ft_server_handler(int signal, siginfo_t *sa, void *d);
void	ft_client(char c, pid_t pid);
void	recieve_message(int signal);

#endif