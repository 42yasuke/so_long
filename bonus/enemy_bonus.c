/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:12:55 by jose              #+#    #+#             */
/*   Updated: 2023/03/10 16:48:17 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_enemy_pos(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return (i * 100 + j);
			j++;
		}
		i++;
	}
	return (-1);
}

static int	ft_next_move(char **map)
{
	int	pi;
	int	pj;
	int	ni;
	int	nj;

	pi = ft_begin_pos(map) / 100;
	pj = ft_begin_pos(map) % 100;
	ni = ft_enemy_pos(map) / 100;
	nj = ft_enemy_pos(map) % 100;
	if (pi != ni)
	{
		if (pi < ni && map[ni - 1][nj] != '1')
			return (NORTH);
		else if (pi > ni && map[ni + 1][nj] != '1')
			return (SOUTH);
	}
	if (pj != nj)
	{
		if (pj < nj && map[ni][nj - 1] != '1')
			return (WEST);
		else if (pj > nj && map[ni][nj + 1] != '1')
			return (EAST);
	}
	return (-1);
}

void	ft_move_enemy(t_win *win)
{
	static char	tmp_bf_mv = '0';
	static char	tmp_af_mv = '0';

	if (ft_enemy_pos(win->map) != -1)
	{
		if (ft_next_move(win->map) != -1)
			ft_move(win->map, &tmp_bf_mv, &tmp_af_mv, ft_next_move(win->map));
	}
}
