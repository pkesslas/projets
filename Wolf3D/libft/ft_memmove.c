/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:13:09 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/02 18:28:11 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	unsigned char	*buffer;

	i = 0;
	tmp1 = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	buffer = (unsigned char*)malloc(sizeof(unsigned char) * (n + 1));

	ft_memcpy(buffer, tmp2, n);
	ft_memcpy(tmp1, buffer, n);
	return (tmp1);
}
