/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/03/05 15:00:06 by jose             ###   ########.fr       */
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
	int		fd;
	char	**map;

	win = ft_initial_window();
	fd = open("/home/jose/C/so_long/maps/test.ber", O_RDWR, 0644);
	if (fd == -1)
		(ft_free_window(win), ft_error(OPEN_FAILED, "open failed"));
	map = ft_valide_map(fd);
	if (!map)
		(ft_free_window(win), ft_error(MAP_NOT_VALID, "map not valid"));

	mlx_put_image_to_window(win->mlx, win->mlx_win, win->lst->img->img, 0, 0);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, &ft_event_manager, win);
	mlx_hook(win->mlx_win, ClientMessage, StructureNotifyMask, &ft_close_win, win);

	mlx_loop(win->mlx);
	mlx_destroy_display(win->mlx);
	(free(win->mlx), free(win), ft_free_all_str(map), close(fd));
	return (EXIT_SUCCESS);
}