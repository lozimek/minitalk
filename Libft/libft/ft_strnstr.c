/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <luozimek@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:16:53 by luozimek          #+#    #+#             */
/*   Updated: 2022/11/13 23:49:05 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if ((!big || !little) && (len == 0))
		return (0);
	i = 0;
	res = (char *) big;
	if (ft_strlen(little) == 0 || big == little)
		return (res);
	while (big[i] && i < len)
	{
		j = 0;
		while (res[i + j] && little[j] && res[i + j] == little[j]
			&& i + j < len)
			j++;
		if (j == ft_strlen(little))
			return (res + i);
		i++;
	}
	return (0);
}
