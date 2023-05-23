/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:19:11 by luozimek          #+#    #+#             */
/*   Updated: 2023/03/29 10:40:04 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putchar(int c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_myputnbr(long long nb)
{
	unsigned int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		ft_putchar('-');
		i++;
		nb = nb * -1;
	}
	if (nb > 9)
		i += ft_myputnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	i++;
	return (i);
}

int	ft_putbase(unsigned long long nbr, char *base)
{
	unsigned int	i;

	i = 0;
	if (nbr > 15)
		i += ft_putbase(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
	i++;
	return (i);
}
