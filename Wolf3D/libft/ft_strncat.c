/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:13:34 by pkesslas          #+#    #+#             */
/*   Updated: 2013/11/26 11:05:59 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int		index;
	int		j;

	index = 0;
	j = 0;
	while (dest[index] != '\0')
	{
		index++;
	}
	while (src[j] != '\0' && n-- > 0)
	{
		dest[index] = src[j];
		j++;
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
