/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:07:35 by ylachhab          #+#    #+#             */
/*   Updated: 2023/01/13 15:00:35 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_convert_decimal(char *str, pid_t si_pid)
{
	int	slen;
	int	total;
	int	decimal;
	int	i;

	total = 0;
	decimal = 1;
	slen = ft_strlen(str);
	i = (slen - 1);
	while (i >= 0)
	{
		if (str[i] == '1')
			total += decimal;
		decimal *= 2;
		i--;
	}
	if (total == 0)
		kill(si_pid, SIGUSR1);
	return (total);
}

void	ft_server_handler(int signal, siginfo_t *sa, void *d)
{
	int			i;
	static char	*stock;
	static int	hand;

	if (hand != sa->si_pid || !hand)
	{
		hand = sa->si_pid;
		i = 0;
		if (stock)
			free(stock);
		stock = 0;
	}
	(void )d;
	i = 0;
	if (signal == SIGUSR1)
		stock = ft_strjoin(stock, "0");
	else if (signal == SIGUSR2)
		stock = ft_strjoin(stock, "1");
	if (ft_strlen(stock) == 8)
	{
		ft_putchar(ft_convert_decimal(stock, sa->si_pid));
		if (stock)
			free(stock);
		stock = NULL;
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;
	pid_t				pid;

	(void)av;
	if (ac > 1)
	{
		write(1, "Error\n", 6);
	}
	else
	{
		pid = getpid();
		ft_printf("%d\n", pid);
		sa.sa_sigaction = &ft_server_handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	return (0);
}
