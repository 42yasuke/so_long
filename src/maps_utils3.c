/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:38:05 by jralph            #+#    #+#             */
/*   Updated: 2023/04/03 13:36:53 by jralph           ###   ########.fr       */
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

int	ft_good_extension(char *str_file)
{
	int	i;

	i = 0;
	if (ft_strlen(str_file) < 4)
		return (false);
	while (str_file[i])
		i++;
	i--;
	if (str_file[i - 3] == '.' && str_file[i - 2] == 'b')
		if (str_file[i - 1] == 'e' && str_file[i] == 'r')
			return (true);
	return (false);
}
