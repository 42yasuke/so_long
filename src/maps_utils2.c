/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:35:42 by jose              #+#    #+#             */
/*   Updated: 2023/03/01 03:43:44 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move_next(int *pos, int *nbr_try, char **map)
{
	int	i;
	int	j;
	int	res;

	i = *pos / 100;
	j = *pos % 100;
	res = 0;
	if (*nbr_try == 2 && map[i + 1][j] != '1' && map[i + 1][j] != '2')
	{
		map[i][j] = '2';
		i++;
		res++;
	}
	else if (*nbr_try == 3 && map[i][j - 1] != '1' && map[i][j - 1] != '2')
	{
			map[i][j] = '2';
			j--;
			res++;
	}
	if (res)
		*pos = i * 100 + j;
	return (res);
}

int	ft_move(int *pos, int *nbr_try, char **map)
{
	int	i;
	int	j;
	int	res;

	i = *pos / 100;
	j = *pos % 100;
	res = 0;
	if (*nbr_try == 0 && map[i - 1][j] != '1' && map[i - 1][j] != '2')
	{
		map[i][j] = '2';
		i--;
		res++;
	}
	else if (*nbr_try == 1 && map[i][j + 1] != '1' && map[i][j + 1] != '2')
	{
		map[i][j] = '2';
		j++;
		res++;
	}
	if (!res)
		res = ft_move_next(pos, nbr_try, map);
	else
		*pos = i * 100 + j;
	return (res);
}

void	ft_move_back(int *pos, int *nbr_try)
{
	int	i;
	int	j;

	i = *pos / 100;
	j = *pos % 100;
	if (*nbr_try == 0)
		i++;
	else if (*nbr_try == 1)
		j--;
	else if (*nbr_try == 2)
		i--;
	else if (*nbr_try == 3)
		j++;
	*pos = i * 100 + j;
}
