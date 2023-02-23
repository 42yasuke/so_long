/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/02/23 20:35:58 by jose             ###   ########.fr       */
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
	t_image	img_space;

	win = ft_initial_window();
	win->mlx = mlx_init();
	if (!win->mlx)
		(ft_error(MLX_INIT_FAILED, "mlx_init"));
	win->mlx_win = mlx_new_window(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "SO_LONG");
	if (!win->mlx_win)
		(ft_free_window(win), ft_error(MLX_WIN_FAILED, "mlx_win"));

	
	img_space.img = mlx_xpm_file_to_image(win.mlx, "/home/jose/C/so_long/image/space.xpm", &img_space.width, &img_space.height);
	img_space.addr = mlx_get_data_addr(img_space.img, &img_space.bpp, &img_space.size_line, &img_space.endian);
	mlx_put_image_to_window(win.mlx, win.mlx_win, img_space.img, 0, 0);
	mlx_loop_hook(win.mlx, &handle_no_event, &img_space);
	mlx_hook(win.mlx_win, 2, 1L<<0, &ft_close_win, &win);
	mlx_loop(win.mlx);
	mlx_destroy_image(win.mlx, img_space.img);
	return (0);
}