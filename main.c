/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:01:41 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 13:19:13 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	vars;

	if (argc != 2)
		return (0);
	vars.mlx_ptr = mlx_init();
	vars.map = NULL;
	read_maap(argv[1], &vars);
	if ((all_check_map(&vars, argv)) != 0)
		error_game(&vars);
	vars.mlx_win = mlx_new_window(vars.mlx_ptr,
			(ft_strlen_get(vars.map[0]) - 1) * 50,
			(count_line_maap(argv[1])) * 50, "So_long");
	reset_count_move(&vars);
	vars.move = 0;
	set_img(&vars);
	init_maap(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, destroy_img, &vars);
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

void	updapte_img_bag(t_game *data, char *img_path)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_bag);
	data->img.bag = img_path;
	data->img.img_bag = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.bag, &(data->img.width), &(data->img.height));
}

void	updapte_img_player(t_game *data, char *img_path)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	data->img.player = img_path;
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
}

void	updapte_img_wall(t_game *data, char *img_path)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	data->img.wall = img_path;
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.wall, &(data->img.width), &(data->img.height));
}
