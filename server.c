/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:16:41 by ylachhab          #+#    #+#             */
/*   Updated: 2023/01/13 00:36:24 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	convert_decimal(char *str)
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
		ft_putchar(convert_decimal(stock));
		if (stock)
			free(stock);
		stock = NULL;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;

	(void)av;
	if (ac != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (ac == 1)
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
