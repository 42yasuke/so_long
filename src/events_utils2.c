/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:58:07 by jose              #+#    #+#             */
/*   Updated: 2023/03/10 02:26:04 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_cpy(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
}

void	ft_add_move(t_win *win)
{
	int			nbr;
	char		*str;

	nbr = ft_atoi(win->move + 7);
	nbr++;
	str = ft_itoa(nbr);
	free((win->move));
	win->move = malloc(sizeof(*str) * (7 + ft_strlen(str) + 1));
	if (!win->move)
		ft_error(MALLOC_FAILED, "malloc failed");
	ft_cpy(win->move, "MOVE : ");
	ft_cpy(win->move + 7, str);
	win->move[7 + ft_strlen(str)] = '\0';
	free(str);
}

int	ft_draw_map(void *win)
{
	static int	is_time = 0;

	if (!(is_time % FPS_ENEMY))
		ft_move_enemy(win);
	if (!(is_time % FPS))
		(ft_put_image_manager((t_win *)win), mlx_do_sync(((t_win *)win)->mlx));
	is_time++;
	if(((t_win *)win)->move)
		ft_is_finished(win);
	return (EXIT_SUCCESS);
}
