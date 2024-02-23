/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:04:02 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/23 15:52:17 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>
#include <stdio.h>

void	print_img(t_game *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		50 * x, 50 * y);
}

int	set_img(t_game *data)
{
	data->img.height = 50;
	data->img.width = 50;
	data->img.player = "./assets/face.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	data->img.background = "./assets/fond.xpm";
	data->img.img_background = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.background, &(data->img.width), &(data->img.height));
	data->img.wall = "./assets/fire.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
	data->img.door = "./assets/porte.xpm";
	data->img.img_door = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.door, &(data->img.width), &(data->img.height));
	data->img.bag = "./assets/caisse1.xpm";
	data->img.img_bag = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.bag, &(data->img.width), &(data->img.height));
	data->img.enemy = "./assets/monstre.xpm";
	data->img.img_enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.enemy, &(data->img.width), &(data->img.height));
	control_img(data);
	return (0);
}

int	count_elem(t_game *data, char c)
{
	int	count;
	int	y;
	int	i;

	y = 0;
	i = 0;
	count = 0;
	while (y < data->numb_line)
	{
		i = 0;
		while (data->map[y][i] != '\n' && data->map[y][i])
		{
			if (data->map[y][i] == c)
				count++;
			i++;
		}
		y++;
	}
	return (count);
}

int	control_img(t_game *data)
{
	if (!data->img.background || !data->img.bag
		|| !data->img.door || !data->img.enemy
		|| !data->img.player)
		destroy_img(data);
	return (0);
}
