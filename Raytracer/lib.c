/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 14:55:41 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/23 14:55:44 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(str) * (int)(ft_strlen(s) + ft_strlen(s2)));
	if (str == NULL)
		return (NULL);
	while (i <= (int)(ft_strlen(s)))
	{
		str[i] = s[i];
		i++;
	}
	str = ft_strcat(str, s2);
	str[ft_strlen(s) + ft_strlen(s2)] = '\0';
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	if (!nptr)
		return (0);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + ((nptr[i] - '0') * sign);
		i++;
	}
	return (result);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i <= (int)n)
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}
