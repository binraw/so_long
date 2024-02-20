/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:02:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/20 13:03:25 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// CHANGEZ LES ARGUMENT PAR LA STRUCTURE DATA AVEC LA MAP
int		all_check_map(t_game *data, char **argv)
{
	int check;
	
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
int     format_check(t_game *data)
{
    int i;
	int	y;
	int value_base;
	
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
	y = count_line_maap(*data->map);
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
	while (y < data->numb_line)
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

	i = 0;
	while (argv[1][i])
		i++;
	i--;
	if (argv[1][i] != 'r' || argv[1][i -1] != 'e' || argv[1][i - 2] != 'b' || argv[1][i - 3] != '.')
		return (-1);
	return (0);
}

int check_number_elem(t_game *data)
{
	int	i;
	int y;
	int c;

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

int check_content(t_game *data)
{
	int	i;
	int y;

	i = 0;
	y = 0;
	while (y < data->numb_line)
	{
		i = 0;
		while (data->map[y][i] != '\n' && data->map[y][i] )
		{
			if (data->map[y][i] != '1' && data->map[y][i] != '0' && data->map[y][i] != 'P'
					&& 	data->map[y][i] != 'E' && data->map[y][i] != 'C' && data->map[y][i] != 'A')
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
	int 	y;
	char	**duplicate;
	
	y = 0;
	duplicate = (char **)malloc(sizeof(char *) * (data->numb_line));
	if (!duplicate)
	{
		// free(duplicate);
		return (NULL);
	}
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
	int i;

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
