/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luka <luka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:05:24 by luka              #+#    #+#             */
/*   Updated: 2023/05/28 17:42:32 by luka             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_receiver(int signal)
{
	static int	bit_index;
	static int	letter;

	if (signal == SIGUSR1)
		letter |= (0x01 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", letter);
		bit_index = 0;
		letter = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac > 1)
	{
		ft_printf("ERROR");
		exit(1);
	}
	pid = getpid();
	ft_printf("PID : \033[0;32m%d\033[0m\n", pid);
	ft_printf("\033[43mWaiting for a message...\033[0m\n");
	while (1)
	{
		signal(SIGUSR1, signal_receiver);
		signal(SIGUSR2, signal_receiver);
		pause();
	}
	return (0);
}
