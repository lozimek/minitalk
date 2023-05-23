/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 05:10:37 by luozimek          #+#    #+#             */
/*   Updated: 2023/05/23 06:20:45 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "Libft/libft/libft.h"
# include "Libft/inc/ft_printf.h"

void	error(int x);
void	transmit_letter(int pid, char letter);
void	check_end_pid(char *str);
void	check_process_id(int pid);
void	check_message(char *str);

/* COLORS */
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define PURPLE "\033[1m\033[38;5;197m"
# define DEF "\033[0m"

# define ERR_WRONGNUM "Error :\nWrong number of arguments\n"
# define ERR_EMPTMESS "Error :\nEmpty message\n"
# define ERR_PIDPOS "Invalid PID :\nPID must be a positive interger"
# define ERR_PIDPROSS "Invalid PID :\nProcess with the given PID does not exist"

#endif