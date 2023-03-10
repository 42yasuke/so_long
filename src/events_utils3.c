/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:03:33 by jose              #+#    #+#             */
/*   Updated: 2023/03/10 01:01:28 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_all_item_col(t_win *win)
{
	int		i;
	int		j;
	char	**map;

	map = win->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);

}

static int	ft_on_exit(t_win *win)
{
	int		i;
	int		j;
	char	**map;

	map = win->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static int	ft_is_over(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'L')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	ft_is_finished(t_win *win)
{
	if (ft_all_item_col(win) && ft_on_exit(win))
		(ft_printf("\nYOU WIN!\n"), ft_free_window(win));
	else if (ft_is_over(win->map))
		(ft_printf("\nGAME OVER! YOU LOOSE!\n"), ft_free_window(win));
}