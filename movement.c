/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:20:04 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/16 16:03:20 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    updapte_img_bag(t_game *data, char *img_path)
{
    mlx_destroy_image(data->mlx_ptr, data->img.img_bag);
    data->img.bag = img_path;
    data->img.img_bag = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.bag, &(data->img.width), &(data->img.height));
}

int    key_hook(int keycode, t_game *data)
{

    if (keycode == XK_w || keycode == XK_Up)
    {
        if (data->count_face == 0)
        {
        control_move(data, data->pos_y - 1, data->pos_x);
        player_move(data, data->pos_y - 1, data->pos_x);
        data->count_face = 1;
        updapte_img_bag(data, "./assets/caisse1.xpm");

            screen_number_move(data);
        }
        else 
        {
             data->img.player = "./assets/back_2.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            
            player_move(data, data->pos_y - 1 , data->pos_x);
            updapte_img_bag(data, "./assets/caisse4.xpm");

            screen_number_move(data);
        }
    }
     else if (keycode == XK_s || keycode == XK_Down)
    {
        if (data->count_back == 0)
        {
            control_move(data, data->pos_y + 1, data->pos_x);
            player_move(data, data->pos_y + 1, data->pos_x);
            data->count_back = 1;
            updapte_img_bag(data, "./assets/caisse3.xpm");

            screen_number_move(data);
        }
        else 
        {
             data->img.player = "./assets/face_2.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            
            player_move(data, data->pos_y + 1 , data->pos_x);
            updapte_img_bag(data, "./assets/caisse1.xpm");

            data->img.wall = "./assets/fire.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
            screen_number_move(data);
        }
    }
     else if (keycode == XK_a || keycode == XK_Left)
    {
        if (data->count_left == 0)
        {
        control_move(data, data->pos_y, data->pos_x - 1);
        player_move(data, data->pos_y, data->pos_x - 1);
            data->count_left = 1;
            updapte_img_bag(data, "./assets/caisse1.xpm");

            screen_number_move(data);
        }
        else 
        {
             data->img.player = "./assets/left_2.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            
            player_move(data, data->pos_y , data->pos_x - 1);
            updapte_img_bag(data, "./assets/caisse4.xpm");

            data->img.wall = "./assets/fire.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
            screen_number_move(data);
        }
        
    }
     else if (keycode == XK_d || keycode == XK_Right)
    {
        if (data->reta_right == 0)
        {
            control_move(data, data->pos_y, data->pos_x + 1);
            player_move(data, data->pos_y, data->pos_x + 1);
            data->reta_right = 1;
            updapte_img_bag(data, "./assets/caisse4.xpm");

            screen_number_move(data);
        }
        else 
        {
             data->img.player = "./assets/right_2.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            
            player_move(data, data->pos_y , data->pos_x + 1);
            updapte_img_bag(data, "./assets/caisse4.xpm");
  
            data->img.wall = "./assets/fire.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
            screen_number_move(data);
        }
    }
    else if (keycode == XK_Escape)
    {
        exit(EXIT_SUCCESS);
    }
    return (0);
}


void    player_move(t_game *data, int new_y, int new_x)
{
    int	last_x;
	int	last_y;
    int collect;
    
    last_x = data->pos_x;
    last_y = data->pos_y;
    collect = count_elem(data, 'C');
    if (data->map[new_y][new_x] == '0')
    {
        data->map[last_y][last_x] = '0';
        data->map[new_y][new_x] = 'P';
        data->pos_x = new_x;
        data->pos_y = new_y;
    }
    else if (data->map[new_y][new_x] == 'C')
    {
        data->map[last_y][last_x] = '0';
        data->map[new_y][new_x] = 'P';
        data->pos_x = new_x;
        data->pos_y = new_y;
        collect--;
    }
    else if (data->map[new_y][new_x] == 'E' && collect == 0)
    {
        exit(EXIT_SUCCESS);
    }
    data->count_left = 0;
    data->reta_right = 0;
    data->count_face = 0;
    data->count_back = 0;
    init_maap(data);
}

void    control_move(t_game *data, int new_y, int new_x)
{
    int	last_x;
	int	last_y;
    
    last_x = data->pos_x;
    last_y = data->pos_y;
    if (last_x < new_x)
    {
        data->img.player = "./assets/right_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            updapte_img_bag(data, "./assets/caisse4.xpm");
  
            data->img.wall = "./assets/fire3.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
        
    }
    if (last_x > new_x)
    {
        data->img.player = "./assets/left_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            updapte_img_bag(data, "./assets/caisse2.xpm");
 
            data->img.wall = "./assets/fire2.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
            
    }
      if (last_y > new_y)
    {
        data->img.player = "./assets/back_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            updapte_img_bag(data, "./assets/caisse4.xpm");
  
            data->img.wall = "./assets/fire2.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
    }
       if (last_y < new_y)
    {
        data->img.player = "./assets/face_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            updapte_img_bag(data, "./assets/caisse2.xpm");

            data->img.wall = "./assets/fire3.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
    }
}
void    screen_number_move(t_game *data)
{
    data->move++;
    ft_printf("Your Score : %d\n", data->move);
}
