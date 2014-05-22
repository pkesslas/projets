/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:33:41 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:49:15 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s)
{
	int		index;
	char	*s2;

	index = 0;
	s2 = (char *)malloc(sizeof(s) * (ft_strlen((char *)s)));
	if (!s2)
		return (0);
	while (s[index] != '\0')
	{
		s2[index] = s[index];
		index++;
	}
	s2[index] = '\0';
	return (s2);
}
