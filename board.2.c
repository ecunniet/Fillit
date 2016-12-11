/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:13:33 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 18:05:31 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block			*get_brick_size(t_block *brick)
{
	t_block	min;
	t_block	*max;
	int		i;

	i = 0;
	min.x = 0;
	min.y = 0;
	max = (t_block *)malloc(sizeof(t_block));
	max->x = 0;
	max->y = 0;
	while (i < 4)
	{
		max->x = ((brick + i)->x > max->x) ? (brick + i)->x : max->x;
		max->y = ((brick + i)->y > max->y) ? (brick + i)->y : max->y;
		min.x = ((brick + i)->x < min.x) ? (brick + i)->x : min.x;
		min.y = ((brick + i)->y < min.y) ? (brick + i)->y : min.y;
		i++;
	}
	max->x = max->x - min.x + 1;
	max->y = max->y - min.y + 1;
	return (max);
}

int				get_maximum_size(t_block **bricks)
{
	int		x;
	int		y;
	int		i;
	t_block	*current;

	x = 0;
	y = 0;
	i = 0;
	while (bricks[i])
	{
		current = get_brick_size(bricks[i]);
		x += current->x;
		y += current->y;
		i++;
	}
	return ((x > y) ? x : y);
}

char			*fill_board(t_board *board)
{
	int i;

	board->board = ft_strnew(board->size * board->size);
	i = 0;
	while (i < board->size * board->size)
	{
		board->board[i] = '.';
		i++;
	}
	return (board->board);
}
