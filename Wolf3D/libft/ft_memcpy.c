/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:27:22 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 17:04:52 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp2;
	size_t		i;

	tmp = dest;
	tmp2 = src;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (dest);
}
