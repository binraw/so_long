/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:40 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 13:04:57 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_up(t_game *data)
{
	if (data->count_face == 0)
	{
		control_move(data, data->pos_y - 1, data->pos_x);
		player_move(data, data->pos_y - 1, data->pos_x);
		data->count_face = 1;
		updapte_img_bag(data, "../assets/caisse1.xpm");
		print_map_string(data);
	}
	else
	{
		if (count_elem(data, 'A') != 0)
			enemy_move(data, data->pos_enemy_y, data->pos_enemy_x - 1);
		updapte_img_player(data, "../assets/back_2.xpm");
		player_move(data, data->pos_y - 1, data->pos_x);
		updapte_img_bag(data, "../assets/caisse4.xpm");
		print_map_string(data);
	}
}

void	key_down(t_game *data)
{
	if (data->count_back == 0)
	{
		control_move(data, data->pos_y + 1, data->pos_x);
		player_move(data, data->pos_y + 1, data->pos_x);
		data->count_back = 1;
		updapte_img_bag(data, "../assets/caisse3.xpm");
		print_map_string(data);
	}
	else
	{
		if (count_elem(data, 'A') != 0)
			enemy_move(data, data->pos_enemy_y, data->pos_enemy_x + 1);
		updapte_img_player(data, "../assets/face_2.xpm");
		player_move(data, data->pos_y + 1, data->pos_x);
		updapte_img_bag(data, "../assets/caisse1.xpm");
		updapte_img_wall(data, "../assets/fire.xpm");
		print_map_string(data);
	}
}

void	key_left(t_game *data)
{
	if (data->count_left == 0)
	{
		control_move(data, data->pos_y, data->pos_x - 1);
		player_move(data, data->pos_y, data->pos_x - 1);
		data->count_left = 1;
		updapte_img_bag(data, "../assets/caisse1.xpm");
		print_map_string(data);
	}
	else
	{
		if (count_elem(data, 'A') != 0)
			enemy_move(data, data->pos_enemy_y -1, data->pos_enemy_x);
		updapte_img_player(data, "../assets/left_2.xpm");
		player_move(data, data->pos_y, data->pos_x - 1);
		updapte_img_bag(data, "../assets/caisse4.xpm");
		updapte_img_wall(data, "../assets/fire2.xpm");
		print_map_string(data);
	}
}

void	key_right(t_game *data)
{
	if (data->reta_right == 0)
	{
		control_move(data, data->pos_y, data->pos_x + 1);
		player_move(data, data->pos_y, data->pos_x + 1);
		data->reta_right = 1;
		updapte_img_bag(data, "../assets/caisse4.xpm");
		print_map_string(data);
	}
	else
	{
		if (count_elem(data, 'A') != 0)
			enemy_move(data, data->pos_enemy_y + 1, data->pos_enemy_x);
		updapte_img_player(data, "../assets/right_2.xpm");
		player_move(data, data->pos_y, data->pos_x + 1);
		updapte_img_bag(data, "../assets/caisse4.xpm");
		updapte_img_wall(data, "../assets/fire3.xpm");
		print_map_string(data);
	}
}

int	key_hook(int keycode, t_game *data)
{
	if (keycode == XK_w || keycode == XK_Up)
		key_up(data);
	else if (keycode == XK_s || keycode == XK_Down)
	{
		key_down(data);
		if (count_elem(data, 'A') != 0)
			enemy_move(data, data->pos_enemy_y, data->pos_enemy_x + 1);
	}
	else if (keycode == XK_a || keycode == XK_Left)
	{
		key_left(data);
		if (count_elem(data, 'A') != 0)
			enemy_move(data, data->pos_enemy_y - 1, data->pos_enemy_x);
	}
	else if (keycode == XK_d || keycode == XK_Right)
	{
		key_right(data);
		if (count_elem(data, 'A') != 0)
			enemy_move(data, data->pos_enemy_y + 1, data->pos_enemy_x);
	}
	else if (keycode == XK_Escape)
		destroy_img(data);
	control_img(data);
	return (0);
}
