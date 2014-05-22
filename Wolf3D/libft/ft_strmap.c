/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:01:55 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:56:37 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		index;

	index = 0;
	str = (char *)malloc (sizeof(char) * ft_strlen(s));
	if (!str)
		return (0);
	while (s[index] != '\0')
	{
		str[index] = f(s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
