/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:40:27 by jose              #+#    #+#             */
/*   Updated: 2023/03/20 21:01:07 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_remove_img(t_win *win)
{
	t_data_img	*tmp;

	tmp = win->lst;
	while (tmp->img->id != SPACIALSHIP)
		tmp = tmp->next;
	mlx_destroy_image(win->mlx, tmp->img->img);
	tmp->img->img = mlx_xpm_file_to_image(win->mlx, \
	"/mnt/nfs/homes/jralph/Desktop/so_long/image/fusee_sf.xpm", \
	&tmp->img->width, &tmp->img->height);
	tmp->img->addr = mlx_get_data_addr(tmp->img->img, &tmp->img->bpp, \
	&tmp->img->size_line, &tmp->img->endian);
	ft_remove_all_backgroud(win);
}

void	ft_add_image(t_win *win, char *path, int id)
{
	t_data_img	*tmp;

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
	tmp->img->img = mlx_xpm_file_to_image(win->mlx, path, \
	&tmp->img->width, &tmp->img->height);
	tmp->img->id = id;
	tmp->img->screened = 0;
	tmp->img->addr = mlx_get_data_addr(tmp->img->img, &tmp->img->bpp, \
	&tmp->img->size_line, &tmp->img->endian);
}

void	ft_add_all_image(t_win *win)
{
	if (!win->lst)
		ft_add_background(win);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	asteroid_sf.xpm", OBSTACLE);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	it1.xpm", ITEM);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	it2.xpm", ITEM);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	it3.xpm", ITEM);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	it4.xpm", ITEM);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	it5.xpm", ITEM);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	it6.xpm", ITEM);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	exit_sf.xpm", EXIT);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	fusee_sf.xpm", SPACIALSHIP);
	ft_add_image(win, "/mnt/nfs/homes/jralph/Desktop/so_long/image/\
	ennemi_sf.xpm", ENEMY);
	ft_remove_all_backgroud(win);
}

void	ft_add_background(t_win *win)
{
	win->lst = malloc(sizeof(*(win->lst)));
	if (!win->lst)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed"));
	win->lst->next = NULL;
	win->lst->img = malloc(sizeof(*(win->lst->img)));
	if (!win->lst->img)
		(ft_free_window(win), ft_error(MALLOC_FAILED, "malloc_failed"));
	win->lst->img->img = mlx_xpm_file_to_image(win->mlx, \
	"/mnt/nfs/homes/jralph/Desktop/so_long/image/noir.xpm", \
	&win->lst->img->width, &win->lst->img->height);
	win->lst->img->addr = mlx_get_data_addr(win->lst->img->img, \
	&win->lst->img->bpp, &win->lst->img->size_line, &win->lst->img->endian);
	win->lst->img->id = BACKGROUND;
	win->lst->img->screened = 0;
}

void	ft_remove_all_backgroud(t_win *win)
{
	t_data_img	*tmp;
	t_image		*img_back;
	t_image		*img;

	tmp = win->lst;
	img_back = tmp->img;
	while (tmp)
	{
		img = tmp->img;
		if (img->id != BACKGROUND)
			ft_remove_backgroud(img, img_back);
		tmp = tmp->next;
	}
}
