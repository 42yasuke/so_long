/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 01:12:55 by jose              #+#    #+#             */
/*   Updated: 2023/03/10 02:36:22 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_enemy_pos(char **map)
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
	ni = ft_enemy_pos(map) /100;
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

static void ft_move_suite(char **map, char *tmp_bf, char *tmp_af, int dir)
{
	int	i;
	int	j;

	i = ft_enemy_pos(map) /100;
	j = ft_enemy_pos(map) % 100;
	if (dir == SOUTH)
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = map[i + 1][j];
		if (map[i + 1][j] != 'P')
			map[i + 1][j] = 'N';
		else
			map[i + 1][j] = 'L';
		map[i][j] = *tmp_af;
	}
	else if (dir == WEST)
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = map[i][j - 1];
		if (map[i][j - 1] != 'P')
			map[i][j - 1] = 'N';
		else
			map[i][j - 1] = 'L';
		map[i][j] = *tmp_af;
	}
}

static void	ft_move(char **map, char *tmp_bf, char *tmp_af, int dir)
{
	int	i;
	int	j;

	i = ft_enemy_pos(map) /100;
	j = ft_enemy_pos(map) % 100;
	if (dir == NORTH)
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = map[i - 1][j];
		if (map[i - 1][j] != 'P')
			map[i - 1][j] = 'N';
		else
			map[i - 1][j] = 'L';
		map[i][j] = *tmp_af;
	}
	else if(dir == EAST)
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = map[i][j + 1];
		if (map[i][j + 1] != 'P')
			map[i][j + 1] = 'N';
		else
			map[i][j + 1] = 'L';
		map[i][j] = *tmp_af;
	}
	ft_move_suite(map, tmp_bf, tmp_af, dir);
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