/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:43:27 by jose              #+#    #+#             */
/*   Updated: 2023/02/23 16:44:28 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESCAPE_KEY 65307

typedef struct s_data {
	void *mlx_ptr;
	void *win_ptr;
} t_data;

int key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_data data;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "Escape Key Detection");
	mlx_hook(data.win_ptr, 2, 1L<<0, &key_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}