/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/02/17 14:50:17 by jralph           ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	t_image	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "SO_LONG");
	//img.width = WINDOW_WIDTH;
	//img.height = WINDOW_HEIGHT;
	img.img = mlx_xpm_file_to_image(mlx, "/home/jose/C/so_long/image/eau.xpm", &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	 mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free(mlx);
	return (0);
}