/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luka <luka@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 05:47:28 by luozimek          #+#    #+#             */
/*   Updated: 2023/05/28 16:20:49 by luka             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_error(char *message)
{
	ft_putstr_fd(PURPLE, 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(DEF, 2);
	exit(EXIT_FAILURE);
}

void	error(int x)
{
	if (x == 1)
		print_error(ERR_WRONGNUM);
	else if (x == 2)
		print_error(ERR_EMPTMESS);
	else if (x == 3)
		print_error(ERR_PIDPOS);
	else if (x == 4)
		print_error(ERR_PIDPROSS);
	else if (x == 5)
		print_error(ERR_MOREARG);
}

void	check_end_pid(char *str)
{
	int	isdigit;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		isdigit = ft_isdigit(str[i]);
		if (isdigit == 0)
			error(2);
		i++;
	}
}

void	check_process_id(int pid)
{
	if (pid <= 0)
		error(3);
	if (kill(pid, 0) != 0)
		error(4);
}

void	check_message(char *str)
{
	if (ft_strlen(str) == 0)
		exit(1);
}
