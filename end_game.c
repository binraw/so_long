#include "so_long.h"

void    destroy_map(t_game *data)
{
    while (game->count_line > 0)
	{
		free(game->map[data->count_line]);
		game->count_line_maap--;
	}
	free(game->map[data->count_line]);
	return ;
}

void    destroy_img(t_game *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img->img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img->img_player);
	mlx_destroy_image(data->mlx_ptr, data->img->img_background);
	mlx_destroy_image(data->mlx_ptr, data->img->img_bag);
	mlx_destroy_image(data->mlx_ptr, data->img->img_door);
	free_map(game);
	free(game->mlx_pointer);
	return ;
}
