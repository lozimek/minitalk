/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:51:10 by luozimek          #+#    #+#             */
/*   Updated: 2023/03/29 10:39:56 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += ft_parscheck(format[i + 1], &args);
			i++;
		}
		else
			counter += write(1, &format[i], 1);
		i++;
	}	
	va_end(args);
	return (counter);
}

/*#include <stdio.h>
int main()
{
	int		og;
	int		mf;
	//char	str[] = "Ecole42";
	int c = 15000;
	int h = 'c';
	

	og = printf("printed: %c\n Oh le test: %x\n", h, c);
	mf = ft_printf("printed: %c\n Oh le test: %x\n", h, c);

	printf("og = %i\n mf = %i\n", og, mf);
}*/