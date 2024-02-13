/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:01:41 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/13 12:05:18 by rtruvelo         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game	vars;
	// t_img *img;
	// void *img;
	// int img_width;
	// int img_height;
	(void)argc;
	
	vars.mlx_ptr = mlx_init();
	read_maap(argv[1], &vars);
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, (ft_strlen(vars.map[0]) - 1) * 50, (count_line_maap(argv[1])) * 50, "Hello world!");
	// img = mlx_xpm_file_to_image(vars.mlx_ptr, "./bucheron.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_win, img, 30, 30);


	set_img(&vars);
	
	init_maap(&vars);
	// printf("%s\n", vars.map[0]);
	// printf("%s\n", vars.map[1]);
	// printf("%s\n", vars.map[2]);
	// printf("%s\n", vars.map[3]);
	// print_img(&vars);
	// print_img(&vars, vars.img.img_background, 0, 0);
	// print_img(&vars, vars.img.img_player, 0, 0);
	// print_img(&vars, vars.img.img_player,  0, 0);
	// print_img(&vars, vars.img.img_background,  1, 1);
	// print_img(&vars, vars.img.img_background,  1, 0);
	// print_img(&vars, vars.img.img_background,  0, 1);
	// print_img(&vars, vars.img.img_bag,  1, 2);
	// print_img(&vars, vars.img.img_door,  0, 2);
	// set_img_background(&vars);
	// print_img_background(&vars);
	// set_img_wall(&vars);
	// print_img_wall(&vars);
	
	mlx_loop(vars.mlx_ptr);
	return (0);
}