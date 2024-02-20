/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:20:04 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/20 13:44:41 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    updapte_img_bag(t_game *data, char *img_path)
{
    mlx_destroy_image(data->mlx_ptr, data->img.img_bag);
    data->img.bag = img_path;
    data->img.img_bag = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.bag, &(data->img.width), &(data->img.height));
}

void    updapte_img_player(t_game *data, char *img_path)
{
     mlx_destroy_image(data->mlx_ptr, data->img.img_player);
    data->img.player = img_path;
    data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}

void    updapte_img_wall(t_game *data, char *img_path)
{
     mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
    data->img.wall = img_path;
    data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
}

void key_up(t_game *data)
{
	 if (data->count_face == 0)
        {
            enemy_move(data, data->pos_enemy_y, data->pos_enemy_x -1);
        control_move(data, data->pos_y - 1, data->pos_x);
        player_move(data, data->pos_y - 1, data->pos_x);
        data->count_face = 1;
        updapte_img_bag(data, "../assets/caisse1.xpm");
		print_map_string(data);
        }
        else 
        {
            enemy_move(data, data->pos_enemy_y, data->pos_enemy_x - 1);
            updapte_img_player(data,  "../assets/back_2.xpm");
            player_move(data, data->pos_y - 1 , data->pos_x);
            updapte_img_bag(data, "../assets/caisse4.xpm");
			print_map_string(data);
        }
}

void key_down(t_game *data)
{
	 if (data->count_back == 0)
        {
            enemy_move(data, data->pos_enemy_y, data->pos_enemy_x + 1);
            control_move(data, data->pos_y + 1, data->pos_x);
            player_move(data, data->pos_y + 1, data->pos_x);
            data->count_back = 1;
            updapte_img_bag(data, "../assets/caisse3.xpm");
			print_map_string(data);
        }
        else 
        {
            enemy_move(data, data->pos_enemy_y, data->pos_enemy_x + 1);
			updapte_img_player(data,  "../assets/face_2.xpm");
            player_move(data, data->pos_y + 1 , data->pos_x);
            updapte_img_bag(data, "../assets/caisse1.xpm");
			updapte_img_wall(data,  "../assets/fire.xpm");
			print_map_string(data);
        }
}

void key_left(t_game *data)
{
 if (data->count_left == 0)
        {
            enemy_move(data, data->pos_enemy_y - 1, data->pos_enemy_x);
        	control_move(data, data->pos_y, data->pos_x - 1);
        	player_move(data, data->pos_y, data->pos_x - 1);
            data->count_left = 1;
            updapte_img_bag(data, "../assets/caisse1.xpm");
			print_map_string(data);
        }
        else 
        {
            enemy_move(data, data->pos_enemy_y -1, data->pos_enemy_x);
        	updapte_img_player(data,  "../assets/left_2.xpm");
            player_move(data, data->pos_y , data->pos_x - 1);
            updapte_img_bag(data, "../assets/caisse4.xpm");
 			updapte_img_wall(data,  "../assets/fire2.xpm");
			print_map_string(data);
        }
}

void	key_right(t_game *data)
{
	  if (data->reta_right == 0)
        {enemy_move(data, data->pos_enemy_y + 1, data->pos_enemy_x);
            control_move(data, data->pos_y, data->pos_x + 1);
            player_move(data, data->pos_y, data->pos_x + 1);
            data->reta_right = 1;
            updapte_img_bag(data, "../assets/caisse4.xpm");
			print_map_string(data);
        }
        else 
        {
            enemy_move(data, data->pos_enemy_y + 1, data->pos_enemy_x);
            updapte_img_player(data,  "../assets/right_2.xpm");
            player_move(data, data->pos_y , data->pos_x + 1);
            updapte_img_bag(data, "../assets/caisse4.xpm");
            updapte_img_wall(data,  "../assets/fire3.xpm");
			print_map_string(data);
		
        }
}

int    key_hook(int keycode, t_game *data)
{
	if (keycode == XK_w || keycode == XK_Up)
		key_up(data);
	else if (keycode == XK_s || keycode == XK_Down)
		key_down(data);

	else if (keycode == XK_a || keycode == XK_Left)
		key_left(data);
	else if (keycode == XK_d || keycode == XK_Right)
		key_right(data);
	else if (keycode == XK_Escape)
        destroy_img(data);	
	control_img(data);	
    return (0);
}

void	reset_count_move(t_game *data)
{
	data->count_left = 0;
	data->reta_right = 0;
	data->count_face = 0;
	data->count_back = 0;
}

int control_img(t_game *data)
{
	if (!data->img.background || !data->img.bag || !data->img.door || !data->img.enemy 
	|| !data->img.player)
		destroy_img(data);
	return (0);
}
void    enemy_move(t_game *data, int new_y, int new_x)
{
	int	last_x;
	int	last_y;
	int collect;

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

void move(t_game *data, int new_y, int new_x)
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

void    player_move(t_game *data, int new_y, int new_x)
{
	int collect;

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
	updapte_img_player(data,  player_path);
	updapte_img_bag(data, bag_path);
	
}


void    control_move(t_game *data, int new_y, int new_x)
{
	int	last_x;
	int	last_y;
    
	last_x = data->pos_x;
	last_y = data->pos_y;
	if (last_x < new_x)
		update_animation(data, "../assets/right_run.xpm", "../assets/caisse4.xpm");

	if (last_x > new_x)
		update_animation(data, "../assets/left_run.xpm", "../assets/caisse2.xpm");

	if (last_y > new_y)
		update_animation(data, "../assets/back_run.xpm", "../assets/caisse4.xpm");
	if (last_y < new_y)
		update_animation(data,"../assets/face_run.xpm", "../assets/caisse2.xpm" );
}

void    screen_number_move(t_game *data)
{
    data->move++;
    ft_printf("Your Score : %d\n", data->move);
}
