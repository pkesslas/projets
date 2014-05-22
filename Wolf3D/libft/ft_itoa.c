/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:13:09 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 17:00:08 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_itoa_nbrlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*str;

	sign = ((n < 0) ? -1 : 1);
	i = ft_itoa_nbrlen(n);
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[i] = 0;
	while (n != 0)
	{
		str[--i] = (n % (10 * sign)) * sign + '0';
		n = n / 10;
	}
	return (str);
}
