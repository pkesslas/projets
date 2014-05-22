/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:09:34 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:58:26 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	while (s[i] == '\n' || s[i] == '\t' || s[i] == 32)
		i++;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	j = j - 1;
	while (str[j] == '\n' || str[j] == '\t' || str[j] == 32)
		j--;
	str[j + 1] = '\0';
	return (str);
}
