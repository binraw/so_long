/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:02:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/14 16:07:07 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHANGEZ LES ARGUMENT PAR LA STRUCTURE DATA AVEC LA MAP

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
			i++;
		if (i != value_base)
			return (-1);
		y++;
	}
	if (y == i)
		return (-1);
	return (0);
}

int		check_wall_map(char **map)
{
	int i;
	int	y;
	
	y = 0;
	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[y][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	y = count_line_maap(*map);
	while (map[y][i] != '\n')
	{
		if (map[y][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int		check_side_wall(char **map)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map[0][i] != '\n')
		i++;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][i - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int check_extension_file(char **argv)
{
	int	i;
	int y;

	i = 0;
	while (argv[1][i])
		i++;
	i--;
	if (argv[1][i] != 'r' || argv[1][i -1] != 'e' argv[1][i - 2] != 'b' || argv[1][i - 3] != '.')
		return (-1);
	return (0);
}
// Faire une copie du tableau ! parcourir remplacer autour du P toutes les case accessible par un P et count les C et E (500)fois environs


int	check_valid_map(t_game *data)
{
	int collectible;
	char **duplicate;

	collectible = count_collect(data);
	duplicate = ft_strdup(data->map);
	
}