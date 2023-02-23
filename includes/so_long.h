/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/02/23 20:43:21 by jose             ###   ########.fr       */
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
# define MLX_INIT_FAILED 3
# define MLX_WIN_FAILED 4

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
	int		id;
}	t_image;

typedef struct	s_data_image
{
	struct s_image		*img;
	struct s_data_image	*next;
}	t_data_img;


typedef struct	s_win
{
	void		*mlx;
	void		*mlx_win;
	t_data_img	*lst;
}	t_win;

/*	error.c	*/
void	ft_error(int err, char *err_msg);

/*	events.c	*/
int		ft_close_win(int keycode, t_win *window);
int		handle_no_event(void *img_space);

/*	utils.c	*/
void	*ft_initial_window(void);

/*	free.c	*/
void	ft_free_all_image(void *mlx, t_data_img *lst);
void	ft_free_window(t_win *window);

#endif