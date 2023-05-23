/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 05:13:17 by luozimek          #+#    #+#             */
/*   Updated: 2023/05/23 06:23:15 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	transmit_letter(int pid, char letter)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		if ((letter & (0x01 << bit_index)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit_index++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*message_ptr;

	i = 0;
	if (ac == 3)
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
		}
		transmit_letter(pid, '\n');
	}
	error(1);
}