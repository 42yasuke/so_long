/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:23:07 by jose              #+#    #+#             */
/*   Updated: 2023/03/20 19:38:44 by jralph           ###   ########.fr       */
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
	if (!str)
		return (NULL);
	if (ft_too_much_bn(str))
		return (NULL);
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

char	**ft_copy_map(char **map)
{
	char	**map_cpy;
	int		i;
	int		j;

	i = 0;
	map_cpy = malloc(sizeof(*map) * (ft_nbr_str(map) + 1));
	if (!map_cpy)
		return (NULL);
	while (map[i])
	{
		j = 0;
		map_cpy[i] = malloc(sizeof(**map) * (ft_strlen(map[i]) + 1));
		if (!map_cpy[i])
			return (ft_free_all_str(map_cpy), NULL);
		while (map[i][j])
		{
			map_cpy[i][j] = map[i][j];
			j++;
		}
		map_cpy[i][j] = '\0';
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}
