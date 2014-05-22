/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:03:23 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:57:19 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strequ(char const *s1, char const *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
		index++;
	if (s1[index] == s2[index])
		return (1);
	else
		return (0);
}
