/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:58:05 by luozimek          #+#    #+#             */
/*   Updated: 2022/11/26 19:49:44 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int c)
{
	int	i;

	i = 1;
	if (c < 0)
		i++;
	while (c / 10)
	{
		i++;
		c /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	nb;
	char		*str;
	int			ngtv;
	int			len;

	nb = n;
	len = ft_nlen(nb);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (0);
	ngtv = 1;
	if (n < 0)
	{
		str[0] = '-';
		ngtv = -1;
	}
	str[len--] = '\0';
	str[len--] = ((n % 10) * ngtv) + '0';
	while (n / 10)
	{
		n /= 10;
		str[len--] = ((n % 10) * ngtv) + '0';
	}
	return (str);
}
