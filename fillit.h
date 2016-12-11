/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:32:19 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 18:06:07 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_block
{
	int		x;
	int		y;
	char	letter;
}				t_block;

typedef struct	s_board
{
	char			*board;
	struct s_board	*best;
	int				size;
	int				square;
}				t_board;

char			*ft_filetomem(char *filename);
void			ft_error(int error);
t_block			**ft_strtopcs(char *str);
int				ft_ispossible(t_board *board, t_block *brick, int x, int y);
t_board			*ft_seat(t_board *board, t_block *brick, int x, int y);
t_board			*ft_unseat(t_board *board, t_block *brick, int x, int y);
void			ft_displayboard(t_board *board);
int				ft_getsize(t_board *board);
void			ft_solve(t_board *board, t_block **bricks);
t_block			*get_brick_size(t_block *brick);
int				get_maximum_size(t_block **bricks);
char			*fill_board(t_board *board);
t_board			*create_boards(t_block **bricks);
t_board			*copy_board(t_board *src, t_board *dst);

#endif
