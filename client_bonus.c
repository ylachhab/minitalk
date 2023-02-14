/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:07:42 by ylachhab          #+#    #+#             */
/*   Updated: 2023/01/07 19:31:09 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_client(char c, pid_t pid)
{
	int		i;
	char	d;

	i = 7;
	while (i >= 0)
	{
		d = c >> i-- & 1;
		if (d == 0)
			kill(pid, SIGUSR1);
		else if (d == 1)
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

void	recieve_message(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "recieve\n", 8);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGUSR1, recieve_message);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			ft_client(av[2][i], pid);
			i++;
		}
		if (av[2][i] == '\0')
		{
			ft_client(av[2][i], pid);
			sleep(1);
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
