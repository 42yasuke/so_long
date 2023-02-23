/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/02/23 17:30:04 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *img_space)
{
	/* This function needs to exist, but it is useless for the moment */
	return ((void)img_space, 0);
}

void	ft_img_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (x * (img->bpp) / 8 + y * (img->size_line));
	*(unsigned int*)dst = color;
}

int	ft_close_win(int keycode, t_win *window)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(window->mlx, window->mlx_win);
	return (0);
}

int	main(void)
{
	t_win	win;
	t_image	img_space;

	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "SO_LONG");
	img_space.img = mlx_xpm_file_to_image(win.mlx, "/home/jose/C/so_long/image/space.xpm", &img_space.width, &img_space.height);
	img_space.addr = mlx_get_data_addr(img_space.img, &img_space.bpp, &img_space.size_line, &img_space.endian);
	mlx_put_image_to_window(win.mlx, win.mlx_win, img_space.img, 0, 0);
	mlx_loop_hook(win.mlx, &handle_no_event, &img_space);
	mlx_hook(win.mlx_win, 2, 1L<<0, &ft_close_win, &win);
	mlx_loop(win.mlx);
	mlx_destroy_image(win.mlx, img_space.img);
	mlx_destroy_display(win.mlx);
	free(win.mlx);
	return (0);
}