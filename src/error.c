/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:48:22 by jralph            #+#    #+#             */
/*   Updated: 2023/04/06 21:05:18 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int err, char *err_msg, t_win *win)
{
	if (err == BAD_PARAMETERS)
		ft_printf("Error: %s\n", err_msg);
	if (err == MALLOC_FAILED)
		ft_printf("%s: %s\n", err_msg, strerror(errno));
	if (err == MLX_INIT_FAILED)
		ft_printf("%s: %s\n", err_msg, strerror(errno));
	if (err == MLX_WIN_FAILED)
		ft_printf("%s: %s\n", err_msg, strerror(errno));
	if (err == OPEN_FAILED)
		ft_printf("%s: %s\n", err_msg, strerror(errno));
	if (err == MAP_NOT_VALID)
		ft_printf("Error: %s\n", err_msg);
	if (err == BAD_EXTENSION)
		ft_printf("Error: %s\n", err_msg);
	if (err == IMAGE_NOT_F)
		ft_printf("Error: %s\n", err_msg);
	if (win)
	{
		if (win->mlx)
			mlx_destroy_display(win->mlx);
		(free(win->mlx), free(win));
	}
	exit(EXIT_FAILURE);
}
