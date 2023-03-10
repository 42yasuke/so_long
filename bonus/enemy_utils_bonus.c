/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:15 by jose              #+#    #+#             */
/*   Updated: 2023/03/10 16:47:09 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_suite2(char **map, char *tmp_bf, char *tmp_af, int dir)
{
	int	i;
	int	j;

	i = ft_enemy_pos(map) / 100;
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

static void	ft_move_suite1(char **map, char *tmp_bf, char *tmp_af, int dir)
{
	int	i;
	int	j;

	i = ft_enemy_pos(map) / 100;
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
	else if (dir == EAST)
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = map[i][j + 1];
		if (map[i][j + 1] != 'P')
			map[i][j + 1] = 'N';
		else
			map[i][j + 1] = 'L';
		map[i][j] = *tmp_af;
	}
}

void	ft_move(char **map, char *tmp_bf, char *tmp_af, int dir)
{
	ft_move_suite1(map, tmp_bf, tmp_af, dir);
	ft_move_suite2(map, tmp_bf, tmp_af, dir);
}
