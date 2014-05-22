/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:48:32 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:54:56 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc (size);
	if (!ptr)
		return (0);
	while (i++ < size)
		ptr[i] = 0;
	return (ptr);
}
