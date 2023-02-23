/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/02/23 18:18:40 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx42/mlx.h"
# include "../mlx42/mlx_int.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <errno.h>
# include <string.h>

/*	window's macro	*/
# define WINDOW_WIDTH 1431
# define WINDOW_HEIGHT 780

/*	keybord's macro	*/
# define KEY_ESC 65307

/*	error's macro*/
# define BAD_INIT 1
# define MALLOC_FAILED 2

/*	image's macro	*/
# define BACKGROUND 0
# define SPACIALSHIP 1
# define ENEMY 2
# define EXIT 3
# define OBSTACLE 4
# define ITEM 5

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct	s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

/*	error.c	*/
void	ft_error(int err, char *err_msg);

#endif