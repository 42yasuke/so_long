/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:55 by jose              #+#    #+#             */
/*   Updated: 2023/02/24 12:35:09 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *win)
{
	/* This function needs to exist, but it is useless for the moment */
	return ((void)win, 0);
}

int	ft_close_win(int keycode, t_win *window)
{
	if (keycode == KEY_ESC)
		ft_free_window(window);
	return (EXIT_SUCCESS);
}