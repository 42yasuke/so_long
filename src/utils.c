/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:14:51 by jose              #+#    #+#             */
/*   Updated: 2023/02/23 21:41:56 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_image()
{
	return ;
}

void	ft_add_all_image(t_win *win)
{
	return ;
}

void	*ft_initial_window(void)
{
	t_win	*win;

	win = malloc(sizeof(*win));
	if (!win)
		return (ft_error(MALLOC_FAILED, "malloc_window"), NULL);
	win->mlx = mlx_init();
	if (!win->mlx)
		(ft_error(MLX_INIT_FAILED, "mlx_init"));
	win->mlx_win = mlx_new_window(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "SO_LONG");
	if (!win->mlx_win)
		(ft_free_window(win), ft_error(MLX_WIN_FAILED, "mlx_win"));
	ft_add_all_image(win);
	return (win);
}