/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/03/01 03:41:11 by jose             ###   ########.fr       */
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
# include <stdbool.h>

/*	window's macro	*/
# define WINDOW_WIDTH 1431
# define WINDOW_HEIGHT 780

/*	keybord's macro	*/
# define KEY_ESC 65307
# define KEY_Z -1
# define KEY_Q -1
# define KEY_D -1
# define KEY_S -1

/*	mouse's macro	*/
# define CROSS_BUTTON 1840902816

/*	error's macro*/
# define BAD_INIT 1
# define MALLOC_FAILED 2
# define MLX_INIT_FAILED 3
# define MLX_WIN_FAILED 4
# define OPEN_FAILED 5
# define MAP_NOT_VALID 6

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
int	ft_close_win(t_win *window);
int		handle_no_event(void *win);
int		ft_event_manager(int keycode, t_win *window);
int		ft_event_manager2(int keycode, t_win *win);

/*	utils.c	*/
void	*ft_initial_window(void);

/*	free.c	*/
void	ft_free_all_image(void *mlx, t_data_img *lst);
void	ft_free_window(t_win *window);
void	ft_free_all_str(char **map);

/*	maps.c	*/
char	**ft_valide_map(int fd);

/*	maps_utils.c	*/
char	**ft_valide_map2(int fd);
int		ft_nbr_str(char **map);
int		ft_nbr_item(char **map);
int		ft_begin_pos(char **map);
int		ft_nbr_move_max(char **map);

/*	maps_utils2.c	*/
int		ft_move(int *pos, int *nbr_try, char **map);
void	ft_move_back(int *pos, int *nbr_try);

#endif