/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:02:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/20 15:21:53 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	all_check_map(t_game *data, char **argv)
{
	int	check;

	check = 0;
	check += format_check(data);
	check += check_wall_map(data);
	check += check_side_wall(data);
	check += check_extension_file(argv);
	check += check_number_elem(data);
	check += check_content(data);
	check += check_valid_map(data);
	return (check);
}

int	format_check(t_game *data)
{
	int	i;
	int	y;
	int	value_base;

	y = 0;
	value_base = 0;
	while (data->map[0][value_base] != '\n' && data->map[0][value_base])
		value_base++;
	while (y < data->numb_line)
	{
		i = 0;
		while (data->map[y][i] != '\n' && data->map[y][i])
			i++;
		if (i != value_base)
			return (-1);
		y++;
	}
	if (y == i)
		return (-1);
	return (0);
}

int	check_wall_map(t_game *data)
{
	int	i;
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
	y = count_line_maap(*data->map);
	while (data->map[y][i] != '\n')
	{
		if (data->map[y][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_side_wall(t_game *data)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (data->map[0][i] != '\n')
		i++;
	while (y < data->numb_line)
	{
		if (data->map[y][0] != '1' || data->map[y][i - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int	check_extension_file(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	i--;
	if (argv[1][i] != 'r' || argv[1][i -1] != 'e' ||
	argv[1][i - 2] != 'b' || argv[1][i - 3] != '.')
		return (-1);
	return (0);
}
