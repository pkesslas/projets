/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:57:17 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 16:55:56 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_strclr(char *s)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
	{
		s[index] = '\0';
		index++;
	}
}
