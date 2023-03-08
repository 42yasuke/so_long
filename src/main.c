/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:16 by jose              #+#    #+#             */
/*   Updated: 2023/03/08 14:14:33 by jose             ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_win	*win;

	if (ac != 2)
		ft_error(BAD_PARAMETERS, "bad parameters");
	win = ft_initial_window(av[1]);
	ft_put_image_manager(win);

	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, &ft_event_manager, win);
	mlx_hook(win->mlx_win, ClientMessage, StructureNotifyMask, &ft_close_win, win);

	mlx_loop(win->mlx);
	mlx_destroy_display(win->mlx);
	(free(win->mlx), free(win));
	return (EXIT_SUCCESS);
}
