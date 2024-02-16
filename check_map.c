/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:02:20 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/16 11:55:28 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHANGEZ LES ARGUMENT PAR LA STRUCTURE DATA AVEC LA MAP
int		all_check_map(t_game *data, char **argv)
{
	int check;
	
	check = 0;
	check += format_check(data);
	printf("check format : %d\n", check);
	check += check_wall_map(data);
	printf("check wall : %d\n", check);
	check += check_side_wall(data);
	printf("check side : %d\n", check);
	check += check_extension_file(argv);
	printf("check exten : %d\n", check);
	check += check_number_elem(data);
	printf("check number : %d\n", check);
	check += check_content(data);
	printf("check content : %d\n", check);
	check += check_valid_map(data);
	printf("check valid : %d\n", check);
	
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
	while (data->map[y] != NULL)
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
	// int y;

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
	// printf("%d\n", i);
	// printf("%d\n", y);
	// printf("%d\n", c);
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
	while (data->map[y])
	{
		i = 0;
		while (data->map[y][i] != '\n' && data->map[y][i] )
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
	return (0);
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
	if (duplicate[y] == NULL)
		y = 1;
	if (y >= data->numb_line)
		y = 1;
	valid_map(data, duplicate, y);
	
	y++;
	
		x++;
	}
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
	while (y < data->numb_line)
	{
		duplicate[y] = ft_strdup(data->map[y]);
		y++;
	}
	return (duplicate);
}
// int	valid_map(t_game *data, char **dup, int y)
// {
// 	int i;

// 	i = 0;
// 	while (dup[y][i] != '\n' && dup[y][i])
// 	{
// 		printf("%c\n", dup[y][i]);
// 		if (dup[y][i] == '0' && (dup[y][i + 1] == 'P' || dup[y][i + 1] == 'P'
// 				|| dup[y + 1][i] == 'P' || dup[y - 1][i] == 'P'))
// 				dup[y][i] = 'P';	
// 		else if (dup[y][i] == 'E' && (dup[y][i + 1] == 'P' || dup[y][i + 1] == 'P'
// 				|| dup[y + 1][i] == 'P' || dup[y - 1][i] == 'P'))
// 			{
// 				dup[y][i] = 'P';
// 				data->numb_exit--;
// 			}
// 		else if (dup[y][i] == 'C' && (dup[y][i + 1] == 'P' || dup[y][i + 1] == 'P'
// 				|| dup[y + 1][i] == 'P' || dup[y - 1][i] == 'P'))
// 			{
// 				dup[y][i] = 'P';
// 				data->numb_collectible--;
// 			}
// 		i++;
// 	}
// 	return (0);
// }


void	good_path(t_game *data, char **dup, int i, int y)
{
	if (dup[y][i] != 1)
	{
		if (dup[y][i] == 'C')
			data->numb_collectible--;
		else if (dup[y][i] == 'C')
			data->numb_exit--;
		dup[y][i] = 'P';
	}
}
int	valid_map(t_game *data, char **dup, int y)
{
	int i;

	i = 0;
	while (dup[y][i] != '\n' && dup[y][i])
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
