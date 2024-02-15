/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:02:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/15 13:12:58 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHANGEZ LES ARGUMENT PAR LA STRUCTURE DATA AVEC LA MAP

int     format_check(t_game *data)
{
    int i;
	int	y;
	int value_base;
	
	y = 0;
	value_base = 0;
	while (data->map[0][value_base] != '\0')
		value_base++;
	while (data->map[y] != NULL)
	{
		i = 0;
		while (data->map[y][i] != '\0')
			i++;
		if (i != value_base)
			return (-1);
		y++;
	}
	if (y == i)
		return (-1);
	return (0);
}

int		check_wall_map(t_game *data)
{
	int i;
	int	y;
	
	y = 0;
	i = 0;
	while (data->map[0][i] != '\n')
	{
		if (data->map[y][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	y = count_line_maap(*map);
	while (data->map[y][i] != '\n')
	{
		if (data->map[y][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int		check_side_wall(t_game *data)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (data->map[0][i] != '\n')
		i++;
	while (data->map[y])
	{
		if (data->map[y][0] != '1' || data->map[y][i - 1] != '1')
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

int check_number_elem(t_game *data)
{
	int	i;
	int y;

	i = count_elem(data, 'E');
	y = count_elem(data, 'P');
	if (i > 1 || i == 0)
		return (-1);
	if (y > 1 || y == 0)
		return (-1);
	return (0);
}

int check_content(t_game *data)
{
	int	i;
	int y;

	i = 0;
	y = 0;
	while (data->map[y])
	{
		i = 0;
		while (data->map[y][i] != 'n')
		{
			if (data->map[y][i] != '1' && data->map[y][i] != '0' && data->map[y][i] != 'P'
					&& 	data->map[y][i] != 'E' && data->map[y][i] != 'C')
			{
				return (-1);
			}
			i++;
		}
		y++;
	}
	reuturn (0);
}

// Faire une copie du tableau ! parcourir remplacer autour du P toutes les case accessible par un P et count les C et E (500)fois environs


int	check_valid_map(t_game *data)
{
	int i;
	int y;
	int x;
	char **duplicate;

	i = 0;
	x = 0;
	data->numb_collectible = count_elem(data, 'C');
	data->numb_exit = count_elem(data, 'E');
	duplicate = dup_map(data);
	y = 1;
	while (x != 500)
	{
	valid_map(duplicate, y);
		y++;
		if (duplicate[y] == NULL)
			y = 1;
		x++;
	}
	if (data->numb_collectible != 0 || data->numb_exit != 0)
		return (-1);
	return (0);
}

char	**dup_map(t_game *data)
{
	int 	y;
	int 	x;
	char	**duplicate;
	
	y = 0;
	x = data->numb_line;
	while (x != 0)
	{
		duplicate[y] = ft_strdup(data->map[y]);
		x--;
		y++;
	}
	return (duplicate);
}
int	valid_map(t_game *data, char **dup, int y)
{
	int i;

	i = 0;
	while (duplicate[y][i] != '\n')
	{
		if (duplicate[y][i] == '0' && (duplicate[y][i + 1] == 'P' || duplicate[y][i + 1] == 'P'
				|| duplicate[y + 1][i] == 'P' || duplicate[y - 1][i] == 'P'))
				duplicate[y][i] = 'P';	
		if (duplicate[y][i] == 'E' && (duplicate[y][i + 1] == 'P' || duplicate[y][i + 1] == 'P'
				|| duplicate[y + 1][i] == 'P' || duplicate[y - 1][i] == 'P'))
			{
				duplicate[y][i] = 'P';
				data->numb_exit--;
			}
		if (duplicate[y][i] == 'C' && (duplicate[y][i + 1] == 'P' || duplicate[y][i + 1] == 'P'
				|| duplicate[y + 1][i] == 'P' || duplicate[y - 1][i] == 'P'))
			{
				duplicate[y][i] = 'P';
				data->numb_collectible--;
			}
		i++;
	}
}
