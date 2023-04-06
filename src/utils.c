/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:14:51 by jose              #+#    #+#             */
/*   Updated: 2023/04/06 20:21:56 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_open_ber_file(t_win *win, char *path)
{
	int	fd;

	fd = open(path, O_RDWR, 0644);
	if (fd == -1)
		ft_error(OPEN_FAILED, "open failed", win);
	win->map = ft_valide_map(fd);
	close(fd);
	if (!win->map)
		ft_error(MAP_NOT_VALID, "map not valid", win);
}

static void	ft_init_all(t_win *win)
{
	win->lst = NULL;
	win->map = NULL;
	win->mlx = NULL;
	win->mlx_win = NULL;
	win->move = NULL;
}

void	*ft_initial_window(char *path)
{
	t_win	*win;
	int		win_w;
	int		win_h;

	win = malloc(sizeof(*win));
	if (!win)
		ft_error(MALLOC_FAILED, "malloc_window", NULL);
	ft_init_all(win);
	ft_open_ber_file(win, path);
	win_w = ft_strlen(win->map[0]);
	win_h = ft_nbr_str(win->map);
	win->mlx = mlx_init();
	if (!win->mlx)
		ft_error(MLX_INIT_FAILED, "mlx_init", win);
	win->mlx_win = mlx_new_window(win->mlx, win_w * SQ, \
	win_h * SQ, "SO_LONG");
	if (!win->mlx_win)
		(ft_free_window(win), ft_error(MLX_WIN_FAILED, "mlx_win", win));
	win->move = ft_strdup("MOVE : 0");
	ft_add_all_image(win);
	return (win);
}

void	ft_put_image_manager(t_win *win)
{
	int		i;
	int		j;
	void	*res;

	i = 0;
	while (win->map[i])
	{
		j = 0;
		if (!i && !j)
			mlx_put_image_to_window(win->mlx, win->mlx_win, \
			win->lst->img->img, j * SQ, i * SQ);
		while (win->map[i][j])
		{
			res = ft_get_img(win->lst, win->map[i][j]);
			if (win->map[i][j] != '0' && res)
				mlx_put_image_to_window(win->mlx, win->mlx_win, \
				res, j * SQ, i * SQ);
			j++;
		}
		i++;
	}
	ft_screened_item(win);
}

void	*ft_get_img(t_data_img *lst, int id)
{
	t_data_img	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->img->id == id && !tmp->img->screened)
			return (tmp->img->img);
		tmp = tmp->next;
	}
	return (NULL);
}
