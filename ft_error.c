/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:10:22 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 15:43:04 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int error)
{
	if (error == 2)
		ft_putstr("Malloc failed to allocate memory.\
		Restart or log elsewhere\n");
	else
		ft_putendl("error");
	exit(EXIT_FAILURE);
}
