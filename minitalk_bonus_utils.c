/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:16:01 by ylachhab          #+#    #+#             */
/*   Updated: 2023/01/07 19:27:15 by ylachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
			sign = -1;
			i++;
	}
	else if (str[i] == '+')
				i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
			result *= 10;
			result += str[i] - 48;
			i++;
	}
	return (result * sign);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	ptr = malloc (sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2 || !s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
