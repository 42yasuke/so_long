/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:14:51 by jose              #+#    #+#             */
/*   Updated: 2023/02/24 11:08:00 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_remove_image(void)
{
	return ;
}

void	ft_add_image(t_win *win, char *path int id)
{
	t_data_img *tmp;

	tmp = win->lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(*tmp));
	if (!tmp->next)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed"));
	tmp = tmp->next;
	tmp->next = NULL;
	tmp->img = malloc(sizeof(*(tmp->img)));
	if (!tmp->img)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed"));
	tmp->img->img = mlx_xpm_file_to_image(win->mlx, path, &tmp->img->width, &tmp->img->height);
	tmp->img->id = id;
	tmp->img->addr = mlx_get_data_addr(tmp->img->img, &tmp->img->bpp, &tmp->img->size_line, &tmp->img->endian);
}

void	ft_add_all_image(t_win *win)
{
	if (!win->lst)
	{
		win->lst = malloc(sizeof(*(win->lst)));
		if (!win->lst)
			(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed"));
		wins->lst->next = NULL;
		win->lst->img = malloc(sizeof(*(win->lst->img)));
		if (!win->lst->img)
			(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed"));
		win->lst->img->img = mlx_xpm_file_to_image(win->mlx, "../image/space.xpm", &win->lst->img->width, &win->lst->img->height);
		win->lst->img->addr = mlx_get_data_addr(win->lst->img->img, &win->lst->img->bpp, &win->lst->img->size_line, &win->lst->img->endian);
		win->lst->img->id = BACKGROUND;
	}
	else
		(void)win;
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