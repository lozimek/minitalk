/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:53:11 by luozimek          #+#    #+#             */
/*   Updated: 2022/11/26 19:51:49 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char			*str;
	unsigned const char		*rts;

	if (!dest && !src)
		return (dest);
	str = dest;
	rts = src;
	while (size--)
		*str++ = *rts++;
	return (dest);
}
