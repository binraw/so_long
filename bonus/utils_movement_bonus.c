/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:10:17 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/23 15:53:45 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move(t_game *data, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = data->pos_x;
	last_y = data->pos_y;
	data->map[last_y][last_x] = '0';
	data->map[new_y][new_x] = 'P';
	data->pos_x = new_x;
	data->pos_y = new_y;
}

void	player_move(t_game *data, int new_y, int new_x)
{
	int	collect;

	collect = count_elem(data, 'C');
	if (data->map[new_y][new_x] == '0')
	{
		move(data, new_y, new_x);
	}
	else if (data->map[new_y][new_x] == 'C')
	{
		move(data, new_y, new_x);
		collect--;
	}
	else if (data->map[new_y][new_x] == 'A')
	{
		ft_printf("You LOOSE !");
		destroy_img(data);
	}
	else if (data->map[new_y][new_x] == 'E' && collect == 0)
	{
		destroy_img(data);
	}
	reset_count_move(data);
	init_maap(data);
}

void	update_animation(t_game *data, char *player_path, char *bag_path)
{
	updapte_img_player(data, player_path);
	updapte_img_bag(data, bag_path);
}

void	control_move(t_game *data, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = data->pos_x;
	last_y = data->pos_y;
	if (last_x < new_x)
		update_animation(data, "./assets/right_run.xpm",
			"./assets/caisse4.xpm");
	if (last_x > new_x)
		update_animation(data, "./assets/left_run.xpm",
			"./assets/caisse2.xpm");
	if (last_y > new_y)
		update_animation(data, "./assets/back_run.xpm",
			"./assets/caisse4.xpm");
	if (last_y < new_y)
		update_animation(data, "./assets/face_run.xpm",
			"./assets/caisse2.xpm" );
}

void	screen_number_move(t_game *data)
{
	data->move++;
	ft_printf("Your Score : %d\n", data->move);
}
