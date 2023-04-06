/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:38:33 by jose              #+#    #+#             */
/*   Updated: 2023/04/06 19:57:52 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_image(void *mlx, t_data_img *lst)
{
	t_data_img	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->img->img)
			mlx_destroy_image(mlx, lst->img->img);
		free(lst->img);
		free(lst);
		lst = tmp;
	}
}

void	ft_free_window(t_win *window)
{
	if (!window)
		return ;
	free((window->move));
	window->move = NULL;
	ft_free_all_str(window->map);
	if (window->mlx)
	{
		ft_free_all_image(window->mlx, window->lst);
		if (window->mlx_win)
			mlx_destroy_window(window->mlx, window->mlx_win);
		mlx_loop_end(window->mlx);
	}
}

void	ft_free_all_str(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
