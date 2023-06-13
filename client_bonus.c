/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:01:54 by luozimek          #+#    #+#             */
/*   Updated: 2023/06/12 13:07:44 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	transmit_letter(int pid, char letter)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		usleep(25);
		if ((letter & (0x01 << (char)bit_index)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(25);
		bit_index++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message_ptr;

	if (ac != 3)
		error(1);
	else
	{
		message_ptr = &av[2][0];
		check_end_pid(&av[1][0]);
		pid = ft_atoi(av[1]);
		check_process_id(pid);
		check_message(&av[2][0]);
		while (*message_ptr != '\0')
		{
			transmit_letter(pid, *message_ptr);
			message_ptr++;
			usleep(25);
		}
		transmit_letter(pid, '\n');
		if (pid == -1)
			ft_printf(RED"Message not received"DEF);
		else
			ft_printf(GREEN"Message received"DEF);
	}
}
