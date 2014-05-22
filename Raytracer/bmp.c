/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awybiera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:29:05 by awybiera          #+#    #+#             */
/*   Updated: 2014/03/26 09:44:04 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <unistd.h>
#include <fcntl.h>

void	copypix(char *pix, int j, char *mir)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		mir[j + i] = pix[i];
		i++;
	}
}

void	reversepix(char *s1, char *s2)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < 3)
	{
		tmp = s1[i];
		s1[i] = s2[i];
		s2[i] = tmp;
		i++;
	}
}

void	reversemirror(char *mir)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = (319 * 3);
	j = (639 * 3);
	while (i < 640 * 479 * 3 + 320 * 3)
	{
		while (i < k)
		{
			reversepix(mir + i, mir + j);
			i += 3;
			j -= 3;
		}
		i += 320 * 3;
		j += (320 * 3) + (640 * 3);
		k += (640 * 3);
	}
}

void	writeheader(int fd)
{
	int		tmp;
	int		size;

	write(fd, "BM", 2);
	size = 54 + ((480 * 640) * 24);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0\x36\0\0\0\x28\0\0\0", 12);
	tmp = 640;
	write(fd, &tmp, 4);
	tmp = 480;
	write(fd, &tmp, 4);
	write(fd, "\x1\0\x18\0\0\0\0\0", 8);
	size -= 54;
	write(fd, &size, 4);
	write(fd, "\x13\xb\0\0\x13\xb\0\0\0\0\0\0\0\0\0\0", 16);
}

void	writefile(char *pix)
{
	int		i[2];
	int		fd;
	int		cnt;
	char	mir[480 * 640 * 3];

	i[0] = 1280 * 480 * 4 - (640 * 4);
	i[1] = 0;
	cnt = 0;
	fd = open("mirror.bmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	writeheader(fd);
	while (i[0] > 0 && (i[1] < (640 * 480 * 3)))
	{
		i[0] -= 4;
		if (cnt == 640)
			i[0] -= (640 * 4) + (cnt = 0);
		copypix(pix + i[0], i[1], mir);
		i[1] += 3;
		cnt++;
	}
	write(fd, mir, 480 * 640 * 3);
	close(fd);
	reversemirror(mir);
	ft_finish_bmp(fd, mir);
}
