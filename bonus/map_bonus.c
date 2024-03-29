/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:51:36 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 13:12:20 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h> 

void	init_maap(t_game *data)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	if (!data->map)
		return ;
	while (y < data->numb_line)
	{
		i = 0;
		while (data->map[y][i] != '\n' && data->map[y][i])
		{
			screen_model(data->map[y][i], data, i, y);
			i++;
		}
		y++;
	}
}

void	screen_model(char c, t_game *data, int i, int y)
{
	if (c == '1')
		print_img(data, data->img.img_wall, i, y);
	if (c == '0')
		print_img(data, data->img.img_background, i, y);
	if (c == 'C')
		print_img(data, data->img.img_bag, i, y);
	if (c == 'E')
		print_img(data, data->img.img_door, i, y);
	if (c == 'A')
	{
		print_img(data, data->img.img_enemy, i, y);
		data->pos_enemy_x = i;
		data->pos_enemy_y = y;
	}
	if (c == 'P')
	{
		print_img(data, data->img.img_player, i, y);
		data->pos_x = i;
		data->pos_y = y;
	}
}

void	read_maap(char *file, t_game *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	data->numb_line = 0;
	alloc_lign(file, data);
	if (!data->map)
	{
		close(fd);
		return ;
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error_game(data);
		return ;
	}
	data->numb_line = count_line_maap(file);
	while (i < data->numb_line)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	count_line_maap(char *file)
{
	int		count;
	int		fd;
	int		reader;
	char	*lign;

	reader = 0;
	fd = open(file, O_RDONLY);
	count = -1;
	lign = "lign";
	while (lign != NULL)
	{
		lign = get_next_line(fd);
		free(lign);
		count++;
	}
	return (count);
}

void	alloc_lign(char *file, t_game *data)
{
	int		line_count;
	int		i;

	i = -1;
	line_count = 0;
	line_count = count_line_maap(file);
	data->map = malloc(sizeof(char *) * line_count + 1);
	if (!data->map)
		destroy_map(data);
}
