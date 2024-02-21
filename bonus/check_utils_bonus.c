/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:18:40 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 11:40:27 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_number_elem(t_game *data)
{
	int	i;
	int	y;
	int	c;

	i = count_elem(data, 'E');
	y = count_elem(data, 'P');
	c = count_elem(data, 'C');
	if (i > 1 || i == 0)
		return (-1);
	if (y > 1 || y == 0)
		return (-1);
	if (c == 0)
		return (-1);
	return (0);
}

int	check_content(t_game *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y < data->numb_line)
	{
		i = 0;
		while (data->map[y][i] != '\n' && data->map[y][i])
		{
			if (data->map[y][i] != '1' && data->map[y][i] != '0' &&
			data->map[y][i] != 'P'
			&& data->map[y][i] != 'E' && data->map[y][i] != 'C'
			&& data->map[y][i] != 'A')
			{
				return (-1);
			}
			i++;
		}
		y++;
	}
	return (0);
}

int	check_valid_map(t_game *data)
{
	int		i;
	int		y;
	int		x;
	char	**duplicate;

	i = 0;
	x = 0;
	data->numb_collectible = count_elem(data, 'C');
	data->numb_exit = count_elem(data, 'E');
	duplicate = dup_map(data);
	y = 1;
	while (x != 500)
	{
		if (duplicate[y] == NULL)
			y = 1;
		if (y + 1 >= data->numb_line)
			y = 1;
		valid_map(data, duplicate, y);
		y++;
		x++;
	}
	destroy_double_char(data, duplicate);
	if (data->numb_collectible != 0 || data->numb_exit != 0)
		return (-1);
	return (0);
}

int	valid_map(t_game *data, char **dup, int y)
{
	int	i;

	i = 1;
	while (dup[y][i] != '\n' && dup[y][i + 1] != '\0')
	{
		if (dup[y][i] == 'P')
		{
			good_path(data, dup, i + 1, y);
			good_path(data, dup, i - 1, y);
			good_path(data, dup, i, y + 1);
			good_path(data, dup, i, y - 1);
		}
		i++;
	}
	return (0);
}
