/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:40:27 by jose              #+#    #+#             */
/*   Updated: 2023/03/08 18:26:48 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_remove_img(t_win *win)
{
	t_data_img	*tmp;
	//t_data_img	*tmp2;

	tmp = win->lst;
	while (tmp->img->id != SPACIALSHIP)
		tmp = tmp->next;
	//tmp2 = 
	mlx_destroy_image(win->mlx, tmp->img->img);
	tmp->img->img = mlx_xpm_file_to_image(win->mlx, \
	"/home/jose/C/so_long/image/fusee_sf.xpm", &tmp->img->width, &tmp->img->height);
	//tmp->img->id = SPACIALSHIP;
	tmp->img->addr = mlx_get_data_addr(tmp->img->img, &tmp->img->bpp, \
	&tmp->img->size_line, &tmp->img->endian);
	/*free(tmp->img);
	free(tmp);*/
	
	//ft_add_image(win, "/home/jose/C/so_long/image/fusee_sf.xpm", SPACIALSHIP);
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
	tmp->img->addr = mlx_get_data_addr(tmp->img->img, &tmp->img->bpp, \
	&tmp->img->size_line, &tmp->img->endian);
}

void	ft_add_all_image(t_win *win)
{
	if (!win->lst)
		ft_add_background(win);
	ft_add_image(win, "/home/jose/C/so_long/image/asteroid_sf.xpm", OBSTACLE);
	ft_add_image(win, "/home/jose/C/so_long/image/item_sf.xpm", ITEM);
	ft_add_image(win, "/home/jose/C/so_long/image/exit_sf.xpm", EXIT);
	ft_add_image(win, "/home/jose/C/so_long/image/fusee_sf.xpm", SPACIALSHIP);
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
	"/home/jose/C/so_long/image/noir.xpm", \
	&win->lst->img->width, &win->lst->img->height);
	win->lst->img->addr = mlx_get_data_addr(win->lst->img->img, \
	&win->lst->img->bpp, &win->lst->img->size_line, &win->lst->img->endian);
	win->lst->img->id = BACKGROUND;
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
