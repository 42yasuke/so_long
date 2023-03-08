/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:36:37 by jose              #+#    #+#             */
/*   Updated: 2023/03/06 23:14:54 by jose             ###   ########.fr       */
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
