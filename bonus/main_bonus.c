/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:01:41 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/23 16:02:39 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	vars;

	if (argc != 2)
		return (0);
	vars.mlx_ptr = mlx_init();
	if (!vars.mlx_ptr)
		exit(EXIT_FAILURE);
	vars.map = NULL;
	read_maap(argv[1], &vars);
	if ((all_check_map(&vars, argv)) != 0)
		error_game(&vars);
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, (ft_strlen_get(vars.map[0]) - 1)
			* 50, (count_line_maap(argv[1])) * 50, "So_long");
	if (!vars.mlx_win)
		destroy_map(&vars);
	reset_count_move(&vars);
	vars.move = 0;
	set_img(&vars);
	init_maap(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, destroy_img, &vars);
	mlx_loop_hook(vars.mlx_ptr, &animation_wall, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}

void	error_game(t_game *data)
{
	destroy_map(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_printf("Error map");
	exit(EXIT_FAILURE);
}
