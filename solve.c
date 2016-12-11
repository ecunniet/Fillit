/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:40:00 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 15:33:29 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_touch(t_board *board, t_block **bricks, int x, int y)
{
	if (ft_ispossible(board, *bricks, x, y))
	{
		if (bricks[1] == NULL)
		{
			if (ft_getsize(ft_seat(board, *bricks, x, y)) < board->best->square)
				board->best = copy_board(board, board->best);
			board = ft_unseat(board, *bricks, x, y);
		}
		else if ((board + 1)->board != NULL)
		{
			if ((ft_getsize(ft_seat(copy_board(board, board + 1), *bricks,
			x, y))) < board->best->square)
				ft_solve(board + 1, bricks + 1);
		}
		return (1);
	}
	return (0);
}

void		ft_solve(t_board *board, t_block **bricks)
{
	int x;
	int y;
	int possible;

	y = 0;
	possible = 0;
	if (ft_getsize(board) >= board->best->square)
		return ;
	while (y < board->best->square)
	{
		x = 0;
		while (x < board->best->square)
		{
			possible += ft_touch(board, bricks, x, y);
			x++;
		}
		y++;
	}
}
