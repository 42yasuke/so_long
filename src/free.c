/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:38:33 by jose              #+#    #+#             */
/*   Updated: 2023/03/09 10:52:48 by jose             ###   ########.fr       */
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
	ft_free_all_image(window->mlx, window->lst);
	ft_free_all_str(window->map);
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_loop_end(window->mlx);
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
