/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:11:38 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:52:40 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*tmp1;
	const char	*tmp2;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && i < n)
	{
		tmp1 = s1;
		tmp2 = s2;
		while ((j + i) < n && *tmp1 == *tmp2 && *tmp2 != '\0')
		{
			tmp1++;
			tmp2++;
			j++;
		}
		if (*tmp2 == '\0')
			return ((char *)s1);
		s1++;
		i++;
	}
	return (NULL);
}
