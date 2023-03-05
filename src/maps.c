/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:04:39 by jose              #+#    #+#             */
/*   Updated: 2023/03/05 02:49:35 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_rectangle(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(map[0]);
	while (map[i])
	{
		if (j != (int)ft_strlen(map[i]))
			return (false);
		i++;
	}
	return (i <= j);
}

static int	ft_is_closed(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == ft_nbr_str(map) - 1)
				if (map[i][j] != '1')
					return (false);
			if (j == 0 || j == (int)ft_strlen(map[i]) - 1)
				if (map[i][j] != '1')
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static int	ft_valide_item(char **map)
{
	int			i;
	int			j;
	static int	item = 0;
	static int	exit = 0;
	static int	begin = 0;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				item++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'P')
				begin++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (item > 0 && exit == 1 && begin == 1);
}

static int	ft_valide_path(char **map)
{
	char	**map_cpy;

	map_cpy = ft_copy_map(map);
	if (!map_cpy)
		return (false);
	ft_first_move(map_cpy);
	if (!ft_is_all_item_collected(map, map_cpy))
		return (ft_free_all_str(map_cpy), false);
	return (ft_free_all_str(map_cpy), true);
}

char	**ft_valide_map(int fd)
{
	char	**map;

	map = ft_valide_map2(fd);
	if (!map)
		return (NULL);
	if (ft_is_rectangle(map) && ft_is_closed(map) && \
	ft_valide_item(map) && ft_valide_path(map))
		return (ft_printf("c une bonne map"), map);
	return (ft_free_all_str(map), NULL);
}
