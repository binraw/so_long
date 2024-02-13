/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:20:04 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/13 14:06:30 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    key_hook(int keycode, t_game *data)
{
    if (keycode == XK_w || keycode == XK_Up)
    {
        player_move(data, data->pos_y - 1, data->pos_x);
        printf("%d\n", 1);
    }
    if (keycode == XK_s || keycode == XK_Down)
    {
        player_move(data, data->pos_y + 1, data->pos_x);
    }
    if (keycode == XK_a || keycode == XK_Left)
    {
        player_move(data, data->pos_y, data->pos_x - 1);
    }
    if (keycode == XK_d || keycode == XK_Right)
    {
        player_move(data, data->pos_y, data->pos_x + 1);
    }
    return (0);
}

void    player_move(t_game *data, int new_y, int new_x)
{
    int	last_x;
	int	last_y;
    
    last_x = data->pos_x;
    last_y = data->pos_y;
    
    if (data->map[new_y][new_x] == '0' || data->map[new_y][new_x] == 'C')
    {
        data->map[last_y][last_x] = '0';
        data->map[new_y][new_x] = 'P';
        data->pos_x = new_x;
        data->pos_y = new_y;
    }
    init_maap(data);
}