/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:48:22 by jralph            #+#    #+#             */
/*   Updated: 2023/02/23 19:29:10 by jose             ###   ########.fr       */
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
	exit(EXIT_FAILURE);
}