/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:48:22 by jralph            #+#    #+#             */
/*   Updated: 2023/02/28 16:08:31 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int err, char *err_msg)
{
	if (err == BAD_INIT)
		ft_printf("%s: %s\n", err_msg, strerror(errno));
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
	exit(EXIT_FAILURE);
}