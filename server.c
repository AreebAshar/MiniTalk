/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:58:35 by hualhash          #+#    #+#             */
/*   Updated: 2023/01/23 16:46:23 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	shift;
	static int	byte;

	if (signal == SIGUSR1)
		byte += 1 << (7 - shift);
	shift++;
	if (shift == 8)
	{
		ft_printf("%c", byte);
		if (!byte)
			ft_printf("\n");
		shift = 0;
		byte = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Process Identifier (PID): %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
