/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetomem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:46:12 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 17:53:07 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_filetomem(char *filename)
{
	int		fd1;
	char	*dst;
	char	c;
	size_t	i;
	size_t	j;

	if ((fd1 = open(filename, O_RDONLY)) < 0)
		ft_error(1);
	i = 0;
	while (read(fd1, &c, 1))
		i++;
	j = 0;
	close(fd1);
	fd1 = open(filename, O_RDONLY);
	dst = ft_strnew(i);
	while (j < i && read(fd1, &c, 1))
	{
		dst[j] = c;
		j++;
	}
	close(fd1);
	if (ft_strlen(dst) != i)
		ft_error(1);
	return (dst);
}
