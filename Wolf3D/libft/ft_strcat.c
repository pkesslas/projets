/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:09:48 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:50:26 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int		index;
	int		j;

	index = 0;
	j = 0;
	while (dest[index] != '\0')
	{
		index++;
	}
	while (src[j] != '\0')
	{
		dest[index] = src[j];
		j++;
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
