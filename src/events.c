/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:55 by jose              #+#    #+#             */
/*   Updated: 2023/03/05 14:54:40 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(t_win *window)
{
	return (ft_free_window(window), EXIT_SUCCESS);
}

int	ft_event_manager(int keycode, t_win *win)
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
		return (ft_close_win(win));
	return (EXIT_SUCCESS);
}
