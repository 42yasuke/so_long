/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:23:42 by jose              #+#    #+#             */
/*   Updated: 2023/03/09 01:54:24 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move_forward(t_win *win, char *tmp_bf, char *tmp_af)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = ft_begin_pos(win->map) / 100;
	j = ft_begin_pos(win->map) % 100;
	if (win->map[i - 1][j] != '1')
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = win->map[i - 1][j];
		win->map[i - 1][j] = 'P';
		win->map[i][j] = *tmp_af;
		res = 1;
	}
	return (res);
}

static int	ft_move_left(t_win *win, char *tmp_bf, char *tmp_af)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = ft_begin_pos(win->map) / 100;
	j = ft_begin_pos(win->map) % 100;
	if (win->map[i][j - 1] != '1')
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = win->map[i][j - 1];
		win->map[i][j - 1] = 'P';
		win->map[i][j] = *tmp_af;
		res = 1;
	}
	return (res);
}

static int	ft_move_right(t_win *win, char *tmp_bf, char *tmp_af)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = ft_begin_pos(win->map) / 100;
	j = ft_begin_pos(win->map) % 100;
	if (win->map[i][j + 1] != '1')
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = win->map[i][j + 1];
		win->map[i][j + 1] = 'P';
		win->map[i][j] = *tmp_af;
		res = 1;
	}
	return (res);
}

static int	ft_move_back(t_win *win, char *tmp_bf, char *tmp_af)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = ft_begin_pos(win->map) / 100;
	j = ft_begin_pos(win->map) % 100;
	if (win->map[i + 1][j] != '1')
	{
		*tmp_af = *tmp_bf;
		*tmp_bf = win->map[i + 1][j];
		win->map[i + 1][j] = 'P';
		win->map[i][j] = *tmp_af;
		res = 1;
	}
	return (res);
}

void	ft_move_manager(t_win *win, int keycode)
{
	int			move;
	static char	tmp_bf_mv = '0';
	static char	tmp_af_mv = '0';

	move = 0;
	if (keycode == KEY_Z)
		move = ft_move_forward(win, &tmp_bf_mv, &tmp_af_mv);
	if (keycode == KEY_Q)
		move = ft_move_left(win, &tmp_bf_mv, &tmp_af_mv);
	if (keycode == KEY_D)
		move = ft_move_right(win, &tmp_bf_mv, &tmp_af_mv);
	if (keycode == KEY_S)
		move = ft_move_back(win, &tmp_bf_mv, &tmp_af_mv);
	if (move)
		ft_add_move(win);
}