/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:02:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/14 14:13:27 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int     format_check(char **map)
{
    int i;
	int	y;
	int value_base;
	
	y = 0;
	value_base = 0;
	while (map[0][value_base] != '\0')
		value_base++;
	while (map[y] != NULL)
	{
		i = 0;
		while (map[y][i] != '\0')
		{
			i++;
		}
		if (i != value_base)
		{
			return (-1);
		}
		y++;
	}
	return (0);
}

int		check_wall_map(char **map)
{
	int i;
	int	y;
	
	i = 0;
	y = 0;
	while (map[y][i] != '\n')
	{
		if (map[y][i] != '1')
			return (-1);
		i++;
	}
	
}
