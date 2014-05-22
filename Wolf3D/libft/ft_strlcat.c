/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:20:00 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:51:19 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*dst;
	const char	*source;
	size_t		len;
	size_t		dst_len;

	dst = dest;
	source = src;
	len = size;
	while (len-- != 0 && *dst != '\0')
		dst++;
	dst_len = dst - dest;
	len = size - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(source));
	while (*source != '\0')
	{
		if (len != 1)
		{
			*dst++ = *source;
			len--;
		}
		source++;
	}
	*dst = '\0';
	return (dst_len + (source - src));
}
