/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:23:07 by jose              #+#    #+#             */
/*   Updated: 2023/03/01 01:02:03 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_valide_map2(int fd)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	char	**map;

	str = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		tmp2 = str;
		str = ft_strjoin(str, tmp);
		free(tmp2);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(str, '\n');
	free(str);
	if (!map)
		return (NULL);
	return (map);
}

int	ft_nbr_str(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_nbr_item(char **map)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	ft_begin_pos(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i * 100 + j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_nbr_move_max(char **map)
{
	return (2 * (ft_nbr_str(map) - 2) * (ft_strlen(map[0]) - 2));
}
