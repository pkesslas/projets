/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:29:42 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:47:18 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int					i;
	unsigned char		*tmps1;
	const unsigned char	*tmps2;

	i = 0;
	tmps1 = s1;
	tmps2 = s2;
	while (n > 0)
	{
		tmps1[i] = tmps2[i];
		if (tmps1[i] == (unsigned char)c)
			return (s1 + 1 + i);
		i++;
		n--;
	}
	return (NULL);
}
