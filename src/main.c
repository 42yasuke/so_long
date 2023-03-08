/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/03/08 13:22:51 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_affiche(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main(void)
{
	t_win	*win;
	int		fd;
	char	**map;

	fd = open("/home/jose/C/so_long/maps/test.ber", O_RDWR, 0644);
	if (fd == -1)
		ft_error(OPEN_FAILED, "open failed");
	map = ft_valide_map(fd);
	if (!map)
		(close(fd), ft_error(MAP_NOT_VALID, "map not valid"));
	win = ft_initial_window(map);
	ft_put_image_manager(win, map);

	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, &ft_event_manager, win);
	mlx_hook(win->mlx_win, ClientMessage, StructureNotifyMask, &ft_close_win, win);

	mlx_loop(win->mlx);
	mlx_destroy_display(win->mlx);
	(free(win->mlx), free(win), ft_free_all_str(map), close(fd));
	return (EXIT_SUCCESS);
}
