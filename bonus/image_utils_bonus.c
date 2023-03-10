/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:36:37 by jose              #+#    #+#             */
/*   Updated: 2023/03/09 15:19:07 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_remove_backgroud(t_image *img, t_image *img_b)
{
	int	i;
	int	j;
	int	colors;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			colors = *(int *)(img->addr + i * (img->bpp / 8) + \
			j * img->size_line);
			if (colors == 0xFFFFFF)
				*(int *)(img->addr + i * (img->bpp / 8) + j * img->size_line) \
				= *(int *)(img_b->addr + i * (img_b->bpp / 8) + \
				j * img_b->size_line);
			j++;
		}
		i++;
	}
}

static void	ft_screened_reset(t_win *win)
{
	t_data_img	*tmp;

	tmp = win->lst;
	while (tmp)
	{
		if (tmp->img->id == ITEM)
			tmp->img->screened = 0;
		tmp = tmp->next;
	}
}

void	ft_screened_item(t_win *win)
{
	t_data_img	*tmp;

	tmp = win->lst;
	while (tmp)
	{
		if (tmp->img->id == ITEM && !tmp->img->screened)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
	{
		tmp->img->screened = 1;
		if (tmp->next && tmp->next->img->id != ITEM)
			ft_screened_reset(win);
	}
	else
		ft_screened_reset(win);
}
