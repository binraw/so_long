/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:20:04 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/14 11:36:07 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    key_hook(int keycode, t_game *data)
{
    if (keycode == XK_w || keycode == XK_Up)
    {
        control_move(data, data->pos_y - 1, data->pos_x);
        player_move(data, data->pos_y - 1, data->pos_x);
        
    }
    if (keycode == XK_s || keycode == XK_Down)
    {
            control_move(data, data->pos_y + 1, data->pos_x);
            player_move(data, data->pos_y + 1, data->pos_x);
            data->count_left = 1;
        
    }
    if (keycode == XK_a || keycode == XK_Left)
    {
          if (data->count_left == 0)
        {
        control_move(data, data->pos_y, data->pos_x - 1);
        player_move(data, data->pos_y, data->pos_x - 1);
            data->count_left = 1;
        }
         else 
        {
             data->img.player = "left_2.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            
            player_move(data, data->pos_y , data->pos_x - 1);
        }
        
    }
    if (keycode == XK_d || keycode == XK_Right)
    {
        control_move(data, data->pos_y, data->pos_x + 1);
        player_move(data, data->pos_y, data->pos_x + 1);
    }
    if (keycode == XK_Escape)
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
    collect = count_collect(data);

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
        data->img.player = "right_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
        
    }
    if (last_x > new_x)
    {
        data->img.player = "left_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
            
            
    }
      if (last_y > new_y)
    {
        data->img.player = "back_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
    }
       if (last_y < new_y)
    {
        data->img.player = "face_run.xpm";
        data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
    }
}