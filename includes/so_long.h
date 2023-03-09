/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:24:25 by jose              #+#    #+#             */
/*   Updated: 2023/03/09 14:54:10 by jose             ###   ########.fr       */
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
# define WINDOW_WIDTH_MAX 30
# define WINDOW_HEIGHT_MAX 15
# define SQ 50
# define FPS 2000

/*	keybord's macro	*/
# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_Q 113
# define KEY_D 100
# define KEY_S 115

/*	mouse's macro	*/
# define CROSS_BUTTON 1840902816

/*	error's macro*/
# define BAD_PARAMETERS 1
# define MALLOC_FAILED 2
# define MLX_INIT_FAILED 3
# define MLX_WIN_FAILED 4
# define OPEN_FAILED 5
# define MAP_NOT_VALID 6

/*	image's macro	*/
# define BACKGROUND 0
# define SPACIALSHIP 80
# define ENEMY 2
# define EXIT 69
# define OBSTACLE 49
# define ITEM 67

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
	int		screened;
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
	char		**map;
	char		*move;
}	t_win;

/*	error.c	*/
void	ft_error(int err, char *err_msg);

/*	events.c	*/
int		ft_close_win(t_win *window);
int		ft_event_manager(int keycode, t_win *window);

/*	events_utils.c	*/
void	ft_move_manager(t_win *win, int keycode);

/*	events_utils2.c	*/
void	ft_add_move(t_win *win);
void	ft_screened_item(t_win *win);
int		ft_draw_map(void *win);

/*	utils.c	*/
void	*ft_initial_window(char *path);
void	ft_put_image_manager(t_win *win);
void	*ft_get_img(t_data_img *lst, int id);

/*	free.c	*/
void	ft_free_all_image(void *mlx, t_data_img *lst);
void	ft_free_window(t_win *window);
void	ft_free_all_str(char **map);

/*	image.c	*/
void	ft_remove_img(t_win *win);
void	ft_add_image(t_win *win, char *path, int id);
void	ft_add_all_image(t_win *win);
void	ft_add_background(t_win *win);
void	ft_remove_all_backgroud(t_win *win);

/*	image_utils.c	*/
void	ft_remove_backgroud(t_image *img, t_image *img_cpy);

/*	maps.c	*/
char	**ft_valide_map(int fd);

/*	maps_utils.c	*/
char	**ft_valide_map2(int fd);
int		ft_nbr_str(char **map);
int		ft_nbr_item(char **map);
int		ft_begin_pos(char **map);
char	**ft_copy_map(char **map);

/*	maps_utils2.c	*/
void	ft_first_move(char **map_cpy);
int		ft_is_all_item_collected(char **map, char **map_cpy);

#endif