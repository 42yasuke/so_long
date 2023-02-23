/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:38:33 by jose              #+#    #+#             */
/*   Updated: 2023/02/23 21:03:02 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_image(void *mlx, t_data_img *lst)
{
	t_data_img	*tmp;
	t_data_img	*tmp_next;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp_next = tmp->next;
		mlx_destroy_image(mlx, tmp->img->img);
		free(tmp->img);
		free(tmp);
		tmp = tmp_next;
	}
	free(lst);
}

void	ft_free_window(t_win *window)
{
	if (!window)
		return ;
	ft_free_all_image(window->mlx, window->lst);
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	free(window);
}