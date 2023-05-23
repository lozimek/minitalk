/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parscheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:51:18 by luozimek          #+#    #+#             */
/*   Updated: 2023/03/29 10:40:00 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_parscheck(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*args, int));
	if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	if (c == '%')
		count += ft_putchar('%');
	if (c == 'd' || c == 'i')
		count += ft_myputnbr(va_arg(*args, int));
	if (c == 'u')
		count += ft_myputnbr(va_arg(*args, unsigned));
	if (c == 'x')
		count += ft_putbase(va_arg(*args, unsigned), "0123456789abcdef");
	if (c == 'X')
		count += ft_putbase(va_arg(*args, unsigned), "0123456789ABCDEF");
	if (c == 'p')
	{	
		count += write(1, "0x", 2);
		count += ft_putbase(va_arg(*args, unsigned long), "0123456789abcdef");
	}
	return (count);
}
