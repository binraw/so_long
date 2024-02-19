/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:01:41 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/19 14:18:10 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include <stdio.h>
#include "so_long_bonus.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_game	vars;
	// pthread_t anim_thread;

	(void)argc;
	
	vars.mlx_ptr = mlx_init();
	read_maap(argv[1], &vars);
	

	if ((all_check_map(&vars, argv)) != 0)
	{
		ft_printf("Error map");
		exit(EXIT_FAILURE);
	}
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, (ft_strlen_get(vars.map[0]) - 1) * 50, (count_line_maap(argv[1])) * 50, "Hello world!");
	vars.count_left = 0;
	vars.reta_right = 0;
	vars.count_back = 0;
	vars.count_face = 0;
	vars.move = 0;

	set_img(&vars);
	init_maap(&vars);
	 
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	
	 mlx_loop_hook(vars.mlx_ptr, &animation_wall, &vars);
	
		// animation_wall(&vars);
		//  pthread_join(anim_thread, NULL);
	mlx_loop(vars.mlx_ptr);
	
	return (0);
}

