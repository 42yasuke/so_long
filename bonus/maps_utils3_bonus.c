/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:16:28 by jralph            #+#    #+#             */
/*   Updated: 2023/03/20 19:23:55 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_too_much_bn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && i == 0)
			return (true);
		if (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n')
			return (true);
		i++;
	}
	return (false);
}
