/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:55 by jose              #+#    #+#             */
/*   Updated: 2023/02/24 14:52:31 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *win)
{
	/* This function needs to exist, but it is useless for the moment */
	return ((void)win, 0);
}

int	ft_close_win(t_win *window)
{
	ft_free_window(window);
	return (EXIT_SUCCESS);
}

int	ft_event_manager(int keycode, t_win *window)
{
	if (keycode == KEY_Z)
		return (0);
	if (keycode == KEY_Q)
		return (0);
	if (keycode == KEY_D)
		return (0);
	if (keycode == KEY_S)
		return (0);
	if (keycode == KEY_ESC)
		return (ft_close_win(window));
	return (EXIT_SUCCESS);
}
