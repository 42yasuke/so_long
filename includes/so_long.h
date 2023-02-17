/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/02/17 14:59:35 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx42/mlx.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <errno.h>
# include <string.h>

# define BAD_INIT 1

/*	error.c	*/
void	ft_error(int err, char *err_msg);

#endif