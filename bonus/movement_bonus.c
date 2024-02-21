/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:20:04 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 11:12:45 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	updapte_img_bag(t_game *data, char *img_path)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_bag);
	data->img.bag = img_path;
	data->img.img_bag = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.bag, &(data->img.width), &(data->img.height));
}

void	updapte_img_player(t_game *data, char *img_path)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.player = img_path;
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}

void	updapte_img_wall(t_game *data, char *img_path)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	data->img.wall = img_path;
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
}

void	reset_count_move(t_game *data)
{
	data->count_left = 0;
	data->reta_right = 0;
	data->count_face = 0;
	data->count_back = 0;
}

void	enemy_move(t_game *data, int new_y, int new_x)
{
	int	last_x;
	int	last_y;
	int	collect;

	last_x = data->pos_enemy_x;
	last_y = data->pos_enemy_y;
	collect = count_elem(data, 'C');
	if (data->map[new_y][new_x] == '0')
	{
		data->map[last_y][last_x] = '0';
		data->map[new_y][new_x] = 'A';
		data->pos_enemy_x = new_x;
		data->pos_enemy_y = new_y;
	}
	else if (data->map[new_y][new_x] == 'P')
	{
		ft_printf("You LOOSE !");
		destroy_img(data);
		exit(EXIT_SUCCESS);
	}
}
