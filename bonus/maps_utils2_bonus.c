/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:35:42 by jose              #+#    #+#             */
/*   Updated: 2023/04/04 07:05:05 by jralph           ###   ########.fr       */
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
	map_cpy[i][j] = '2';
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

int	ft_valide_nbr_enemy(char **map)
{
	int	i;
	int	j;
	int	nbr_enemy;

	i = 0;
	nbr_enemy = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				nbr_enemy++;
			j++;
		}
		i++;
	}
	return (nbr_enemy < 2);
}
