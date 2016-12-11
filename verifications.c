/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:31:37 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/27 14:27:45 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_format(char *s)
{
	char	*cmp;
	int		i;
	int		retvalue;

	cmp = ft_strdup("....\n....\n....\n....\n-");
	i = 0;
	retvalue = 0;
	while (s[i])
	{
		if (cmp[i % 21] == '.')
			retvalue += (s[i] == '.' || s[i] == '#') ? 0 : 1;
		else if (cmp[i % 21] == '\n')
			retvalue += (s[i] == '\n') ? 0 : 1;
		else
			retvalue += (s[i] == '\0' || s[i] == '\n') ? 0 : 1;
		i++;
	}
	return ((retvalue > 0) ? 0 : 1);
}

static unsigned int	ft_countpcs(char *str)
{
	unsigned int len;
	unsigned int i;
	unsigned int pcs;

	len = ft_strlen(str) + 1;
	if (len % 21 != 0)
		return (0);
	i = 0;
	pcs = 0;
	while (i < len)
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			pcs++;
		if (str[i] != '\n' && str[i] != '\0' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	if ((len) / 21 == pcs)
		return (ft_format(str) * pcs);
	return (0);
}

static int			ft_verifpcs(char *str)
{
	int				i;
	unsigned int	nblocks;
	unsigned int	n;

	i = 0;
	n = 0;
	nblocks = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			nblocks++;
			n = (str[i - 1] == '#') ? n + 1 : n;
			n = (str[i + 1] == '#') ? n + 1 : n;
			if (i - 5 >= 0)
				n = (str[i - 5] == '#') ? n + 1 : n;
			if (i + 5 < 21)
				n = (i + 5 < 21 && str[i + 5] == '#') ? n + 1 : n;
		}
		i++;
	}
	return ((nblocks == 4 && n >= 6) ? 1 : 0);
}

static t_block		*ft_strtopc(char *str, int letter)
{
	unsigned int	i;
	int				j;
	t_block			*pcs;

	i = 0;
	j = 0;
	if (!(pcs = (t_block *)malloc(sizeof(t_block) * 4)))
		ft_error(2);
	while (i < 21)
	{
		if (str[i] == '#' && j < 4)
		{
			(pcs + j)->x = i % 5 - ((j != 0) ? pcs->x : 0);
			(pcs + j)->y = i / 5 - ((j != 0) ? pcs->y : 0);
			j++;
		}
		i++;
	}
	pcs->x = 0;
	pcs->y = 0;
	pcs->letter = letter + 'A';
	return (pcs);
}

t_block				**ft_strtopcs(char *str)
{
	unsigned int	npcs;
	unsigned int	i;
	t_block			**pcs;

	npcs = ft_countpcs(str);
	if (npcs == 0)
		ft_error(1);
	i = 0;
	pcs = (t_block **)malloc(sizeof(t_block *) * (npcs + 1));
	while (i < npcs)
	{
		if (ft_verifpcs(str + (i * 21)) == 0)
			ft_error(1);
		pcs[i] = ft_strtopc(str + (i * 21), i);
		i++;
	}
	pcs[npcs] = NULL;
	return (pcs);
}
