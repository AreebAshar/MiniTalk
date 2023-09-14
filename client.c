/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:02:35 by hualhash          #+#    #+#             */
/*   Updated: 2023/01/23 20:45:16 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while (*str == 64 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > LONG_MAX && sign == 1)
			return (-1);
		else if (res > LONG_MAX && sign == -1)
			return (0);
		str++;
	}
	return (res * sign);
}

void	send_bit(int pid, char *message, int len)
{
	int	shift;
	int	i;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if (message[i] >> shift & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(160);
			shift--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		ft_printf("Error! Did you mean: ./client [pid] ['message']?\n");
	else
	{
		pid = ft_atoi(av[1]);
		if (pid == 0)
		{
			ft_printf("Incorrect PID!!\n");
			return (0);
		}
		if (pid < 0)
		{
			ft_printf("Error! Did you mean: %d\n", (pid * -1));
			return (0);
		}
		send_bit(pid, av[2], ft_strlen(av[2]));
	}
	return (0);
}
