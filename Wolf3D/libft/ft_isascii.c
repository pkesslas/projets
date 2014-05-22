/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:13:07 by pkesslas          #+#    #+#             */
/*   Updated: 2013/12/21 17:04:03 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}
