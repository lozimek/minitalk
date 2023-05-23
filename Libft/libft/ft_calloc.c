/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:58:55 by luozimek          #+#    #+#             */
/*   Updated: 2022/11/13 20:09:58 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	t = malloc(count * size);
	if (!t)
		return (NULL);
	ft_bzero (t, (count * size));
	return (t);
}
