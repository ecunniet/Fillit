/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:49:32 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 18:30:23 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board			*copy_board(t_board *src, t_board *dst)
{
	int i;

	i = 0;
	while (i < src->size * src->size)
	{
		dst->board[i] = src->board[i];
		dst->size = src->size;
		dst->square = ft_getsize(src);
		i++;
	}
	return (dst);
}

static t_board	*create_boards2(t_board *boards, int len, t_board *best)
{
	int i;

	i = 0;
	while (i < len + 1)
	{
		(boards + i)->size = best->size;
		(boards + i)->board = fill_board(boards + i);
		(boards + i)->best = best;
		(boards + i)->square = 0;
		i++;
	}
	return (boards);
}

t_board			*create_boards(t_block **bricks)
{
	int			size;
	int			len;
	t_board		*boards;
	t_board		*best;

	len = 0;
	while (bricks[len])
		len++;
	best = (t_board *)malloc(sizeof(t_board));
	boards = (t_board *)malloc(sizeof(t_board) * (len + 1));
	size = (len > 3) ? get_maximum_size(bricks) / 2 : get_maximum_size(bricks);
	best->size = size;
	best->square = size + 1;
	best->best = NULL;
	best->board = fill_board(best);
	return (create_boards2(boards, len, best));
}
