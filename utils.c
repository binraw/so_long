/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:04:02 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/08 14:29:40 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void	print_img(t_game *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}

// void print_img(t_game *data)
// {
//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_player, 0, 0);
// }

int set_img(t_game *data)
{
	data->img.height = 0;
	data->img.width = 0;
	data->img.player = "player.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	data->img.background = "solsol.xpm";
	data->img.img_background = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.background, &(data->img.width), &(data->img.height));
	data->img.wall = "murmur.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));


	// if (!data->img.img_player)
    // {
    //     return 1; // Erreur
    // }

    return 0; // Succès
}

// void print_img_background(t_game *data)
// {
//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_background, 100, 200);
// }

// int set_img_background(t_game *data)
// {
// 	data->img.height = 10;
// 	data->img.width = 10;
// 	data->img.background = "solsol.xpm";
// 	data->img.img_background = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->img.background, &(data->img.width), &(data->img.height));


// 	if (!data->img.img_background)
//     {
//         return 1; // Erreur
//     }

//     return 0; // Succès
// }

// void print_img_wall(t_game *data)
// {
//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_wall, 150, 0);
// }

// int set_img_wall(t_game *data)
// {
// 	data->img.height = 10;
// 	data->img.width = 10;
// 	data->img.wall = "murmur.xpm";
// 	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->img.wall, &(data->img.width), &(data->img.height));


// 	if (!data->img.img_wall)
//     {
//         return 1; // Erreur
//     }

//     return 0; // Succès
// }