/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:35:42 by jose              #+#    #+#             */
/*   Updated: 2023/03/06 23:09:26 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_make_move(char **map_cpy, int i, int j)
{
	int	res;

	res = 0;
	if (map_cpy[i - 1][j] != '1' && map_cpy[i - 1][j] != '2')
	{
		res = 1;
		map_cpy[i - 1][j] = '2';
	}
	if (map_cpy[i][j + 1] != '1' && map_cpy[i][j + 1] != '2')
	{
		res = 1;
		map_cpy[i][j + 1] = '2';
	}
	if (map_cpy[i + 1][j] != '1' && map_cpy[i + 1][j] != '2')
	{
		res = 1;
		map_cpy[i + 1][j] = '2';
	}
	if (map_cpy[i][j - 1] != '1' && map_cpy[i][j - 1] != '2')
	{
		res = 1;
		map_cpy[i][j - 1] = '2';
	}
	return (res);
}

static void	ft_all_possible_move(char **map_cpy)
{
	int	i;
	int	j;
	int	moved;

	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		moved = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == '2' && ft_make_move(map_cpy, i, j))
				moved = 1;
			j++;
		}
		if (moved)
			i = -1;
		i++;
	}
}

void	ft_first_move(char **map_cpy)
{
	int	i;
	int	j;

	i = ft_begin_pos(map_cpy) / 100;
	j = ft_begin_pos(map_cpy) % 100;
	if (map_cpy[i - 1][j] == '0')
		map_cpy[i - 1][j] = '2';
	if (map_cpy[i][j + 1] == '0')
		map_cpy[i][j + 1] = '2';
	if (map_cpy[i + 1][j] == '0')
		map_cpy[i + 1][j] = '2';
	if (map_cpy[i][j - 1] == '0')
		map_cpy[i][j - 1] = '2';
	ft_all_possible_move(map_cpy);
}

int	ft_is_all_item_collected(char **map, char **map_cpy)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				if (map_cpy[i][j] != '2')
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}
