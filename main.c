/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:01:41 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/08 11:28:09 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>








// int	close(t_game *vars)
// {
// 	mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
// 	return (0);
// }

int	main(void)
{
	t_game	vars;
	// t_img *img;
	// void *img;
	// int img_width;
	// int img_height;
	
	vars.mlx_ptr = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, 800, 600, "Hello world!");
	// img = mlx_xpm_file_to_image(vars.mlx_ptr, "./bucheron.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, img, 30, 30);


	set_img(&vars);
	print_img(&vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}