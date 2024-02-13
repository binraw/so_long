/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:04:02 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/13 11:27:36 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void	print_img(t_game *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		50 * x, 50 * y);
}

// void print_img(t_game *data)
// {
//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_player, 0, 0);
// }

int set_img(t_game *data)
{
	data->img.height = 50;
	data->img.width = 50;
	data->img.player = "ninja.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	data->img.background = "foret.xpm";
	data->img.img_background = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.background, &(data->img.width), &(data->img.height));
	data->img.wall = "muuuur.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
			data->img.door = "porte.xpm";
	data->img.img_door = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.door, &(data->img.width), &(data->img.height));
	data->img.bag = "coffre.xpm";
	data->img.img_bag = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.bag, &(data->img.width), &(data->img.height));


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