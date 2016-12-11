/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:54:29 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/26 16:26:24 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_displayboard(t_board *board)
{
	int i;
	int j;
	int size;

	i = 0;
	size = board->square + 1;
	while (i < board->size && i < size)
	{
		j = 0;
		while (j < board->size && j < size)
		{
			ft_putchar(board->board[i * board->size + j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_getsize(t_board *board)
{
	int i;
	int	current;

	i = 0;
	current = 0;
	while (i < board->size * board->size)
	{
		if (board->board[i] != '.' &&
			(i / board->size > current || i % board->size > current))
			current = (i % board->size > i / board->size) ?
						i % board->size : i / board->size;
		i++;
	}
	board->square = current;
	return (current);
}

int		ft_ispossible(t_board *board, t_block *brick, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((brick + i)->x + x < 0 || (brick + i)->y + y < 0 ||
			(brick + i)->x + x >= board->size ||
			(brick + i)->y + y >= board->size)
			return (0);
		if (board->board[((brick + i)->x + x) +
			board->size * ((brick + i)->y + y)] != '.')
			return (0);
		i++;
	}
	return (1);
}

t_board	*ft_seat(t_board *board, t_block *brick, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		board->board[((brick + i)->x + x) +
		board->size * ((brick + i)->y + y)] = brick->letter;
		i++;
	}
	return (board);
}

t_board	*ft_unseat(t_board *board, t_block *brick, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		board->board[((brick + i)->x + x) +
		board->size * ((brick + i)->y + y)] = '.';
		i++;
	}
	return (board);
}
