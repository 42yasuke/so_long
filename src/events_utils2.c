/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:58:07 by jose              #+#    #+#             */
/*   Updated: 2023/03/08 19:42:25 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_move(t_win *win)
{
	int			nbr;
	char		*str;
	static char	*str2 = "MOVE : ";
	int			i;

	i = 0;
	nbr = ft_atoi(win->move + 7);
	nbr++;
	str = ft_itoa(nbr);
	win->move = malloc(sizeof(*str) * (ft_strlen(str2) + ft_strlen(str) + 1));
	if (!win->move)
		ft_error(MALLOC_FAILED, "malloc failed");
	while (str2[i])
	{
		win->move[i] = str2[i];
		i++;
	}
	while (*str)
	{
		win->move[i] = *str;
		i++;
		str++;
	}
	win->move[i] = '\0';
}
