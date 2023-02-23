/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:48:22 by jralph            #+#    #+#             */
/*   Updated: 2023/02/17 14:59:52 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int err, char *err_msg)
{
	if (err == BAD_INIT)
		ft_printf("%s: %s\n", err_msg, strerror(errno));
	if (err == MALLOC_FAILED)
		ft_printf("%s: %s\n", err_msg, strerror(errno));
	exit(EXIT_FAILURE);
}