/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 13:16:59 by glavanan          #+#    #+#             */
/*   Updated: 2014/02/24 13:19:41 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[c] != '\0')
	{
		dest[i] = src[c];
		c++;
		i++;
		dest[i] = src[c];
	}
	return (dest);
}
