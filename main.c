/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:16:45 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 15:42:07 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_bricks(t_block **bricks)
{
	int i;
	int j;

	i = 0;
	while (bricks[i])
	{
		j = 0;
		while (j < 4)
		{
			free(bricks[i] + j);
			j++;
		}
		free(bricks[i]);
		i++;
	}
}

void	free_memory(t_board *boards, t_block **bricks, char *file_str)
{
	int i;

	i = 0;
	free(boards->best->board);
	free(boards->best);
	while ((boards + i)->board != NULL)
	{
		free((boards + i)->board);
		i++;
	}
	free(boards);
	free_bricks(bricks);
	free(file_str);
}

int		main(int ac, char **av)
{
	char	*str;
	t_block	**bricks;
	t_board	*boards;

	if (ac != 2)
		ft_error(1);
	str = ft_filetomem(av[1]);
	bricks = ft_strtopcs(str);
	boards = create_boards(bricks);
	ft_solve(boards, bricks);
	ft_displayboard(boards->best);
	return (0);
}
