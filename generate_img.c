/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:59:32 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/20 14:20:20 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			data->map[y][i] != 'P' && data->map[y][i] != 'E'
			&& data->map[y][i] != 'C')
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

char	**dup_map(t_game *data)
{
	int		y;
	char	**duplicate;

	y = 0;
	duplicate = (char **)malloc(sizeof(char *) * (data->numb_line));
	while (y < data->numb_line)
	{
		duplicate[y] = ft_strdup_get(data->map[y]);
		y++;
	}
	return (duplicate);
}

void	good_path(t_game *data, char **dup, int i, int y)
{
	if (dup[y][i] != '1')
	{
		if (dup[y][i] == 'C')
			data->numb_collectible--;
		else if (dup[y][i] == 'E')
		{
			data->numb_exit--;
			dup[y][i] = '1';
			return ;
		}
		dup[y][i] = 'P';
	}
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
