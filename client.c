/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:33:48 by ylachhab          #+#    #+#             */
/*   Updated: 2023/01/13 01:34:40 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_client(av[2][i], pid);
			i++;
		}
		if (av[2][i] == '\0')
			ft_client(av[2][i], pid);
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
