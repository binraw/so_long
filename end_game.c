/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:16:51 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 13:39:40 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *data)
{
	int	i;
	int	y;

	i = 0;
	y = data->numb_line - 1;
	if (!data->map)
	{
		free(data->map[0]);
		return ;
	}
	while (y > 0)
	{
		free(data->map[y]);
		y--;
	}
	if (y >= 0)
		free(data->map[y]);
	free(data->map);
	return ;
}

void	destroy_double_char(t_game *data, char **map)
{
	int	i;
	int	y;

	i = 0;
	y = data->numb_line - 1;
	if (!map)
	{
		free(map[0]);
		return ;
	}
	while (y > 0)
	{
		free(map[y]);
		y--;
	}
	free(map[y]);
	free(map);
	return ;
}

int	destroy_img(t_game *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_background);
	mlx_destroy_image(data->mlx_ptr, data->img.img_bag);
	mlx_destroy_image(data->mlx_ptr, data->img.img_door);
	destroy_map(data);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

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

void	reset_count_move(t_game *data)
{
	data->count_left = 0;
	data->reta_right = 0;
	data->count_face = 0;
	data->count_back = 0;
}
