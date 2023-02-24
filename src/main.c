/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/02/24 12:39:27 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (x * (img->bpp) / 8 + y * (img->size_line));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_win	*win;

	win = ft_initial_window();

	mlx_put_image_to_window(win->mlx, win->mlx_win, win->lst->img->img, 0, 0);
	mlx_loop_hook(win->mlx, &handle_no_event, win);
	mlx_hook(win->mlx_win, 2, 1L<<0, &ft_close_win, win);
	mlx_loop(win->mlx);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	free(win);
	return (0);
}