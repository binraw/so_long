/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:01:41 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/16 11:15:24 by rtruvelo         ###   ########.fr       */
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
	
	// printf("%d\n", all_check_map(&vars, argv));
	if ((all_check_map(&vars, argv)) != 0)
	{
		// close(argv[1]);
		printf("Error map");
		exit(EXIT_FAILURE);
	}
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, (ft_strlen(vars.map[0]) - 1) * 50, (count_line_maap(argv[1])) * 50, "Hello world!");

	vars.count_left = 0;
	vars.reta_right = 0;
	vars.count_back = 0;
	vars.count_face = 0;
	

	set_img(&vars);
	
	init_maap(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);


	
	mlx_loop(vars.mlx_ptr);
	return (0);
}