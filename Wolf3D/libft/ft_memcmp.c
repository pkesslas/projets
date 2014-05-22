/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:17:21 by pkesslas          #+#    #+#             */
/*   Updated: 2013/11/26 11:04:31 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*(tmp1++) != *(tmp2++))
			return (*(--tmp1) - *(--tmp2));
	}
	return (0);
}
