/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:11:22 by pkesslas          #+#    #+#             */
/*   Updated: 2013/11/27 17:11:29 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			len;

	c1 = *s1;
	c2 = *s2;
	len = ft_strlen(s1);
	if (ft_strcmp(s1, s2) == 0 && n > len)
		return (0);
	while (c1 == c2 && n-- > 0)
	{
		c1 = *(s1++);
		c2 = *(s2++);
	}
	return (c1 - c2);
}
