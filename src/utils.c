/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:14:51 by jose              #+#    #+#             */
/*   Updated: 2023/03/08 13:17:04 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_initial_window(char **map)
{
	t_win	*win;
	int		win_w;
	int		win_h;

	win_w = ft_strlen(map[0]);
	win_h = ft_nbr_str(map);
	win = malloc(sizeof(*win));
	if (!win)
		return (ft_error(MALLOC_FAILED, "malloc_window"), NULL);
	win->mlx = mlx_init();
	if (!win->mlx)
		(ft_error(MLX_INIT_FAILED, "mlx_init"));
	win->mlx_win = mlx_new_window(win->mlx, win_w * SQ, \
	win_h * SQ, "SO_LONG");
	if (!win->mlx_win)
		(ft_free_window(win), ft_error(MLX_WIN_FAILED, "mlx_win"));
	win->lst = NULL;
	ft_add_all_image(win);
	return (win);
}

void	ft_put_image_manager(t_win *win, char **map)
{
	int		i;
	int		j;
	void	*res;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (!i && !j)
			mlx_put_image_to_window(win->mlx, win->mlx_win, \
			win->lst->img->img, j * SQ, i * SQ);
		while (map[i][j])
		{
			res = ft_get_img(win->lst, map[i][j]);
			if (map[i][j] != '0')
				mlx_put_image_to_window(win->mlx, win->mlx_win, \
				res, j * SQ, i * SQ);
			j++;
		}
		i++;
	}
}

void	*ft_get_img(t_data_img *lst, int id)
{
	t_data_img	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->img->id == id)
			return (tmp->img->img);
		tmp = tmp->next;
	}
	return (NULL);
}
