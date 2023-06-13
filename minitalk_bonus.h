/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:03:36 by luozimek          #+#    #+#             */
/*   Updated: 2023/06/12 12:04:09 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "Libft/libft/libft.h"
# include "Libft/inc/ft_printf.h"

void	error(int x);
void	transmit_letter(int pid, char letter);
void	check_end_pid(char *str);
void	check_process_id(int pid);
void	check_message(char *str);
void	signal_receiver(int signal);

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

# define ERR_WRONGNUMC "Error client :\nWrong number of arguments.\n"
# define ERR_WRONGNUMS "Error server :\nWrong number of arguments.\n"
# define ERR_EMPTMESS "Error :\nEmpty message.\n"
# define ERR_PIDPOS "Invalid PID :\nPID must be a positive interger.\n"
# define ERR_PIDPROSS "Invalid PID :\nProcess given PID does not exist.\n"
# define ERR_MOREARG "Error :\nNo additional arguments should be provided.\n"

#endif