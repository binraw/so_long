#include "so_long.h"

void    destroy_map(t_game *data)
{
    while (data->numb_line > 0)
	{
		free(data->map[data->numb_line]);
		data->numb_line--;
	}
	free(data->map[data->numb_line]);
	return ;
}

void    destroy_img(t_game *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_background);
	mlx_destroy_image(data->mlx_ptr, data->img.img_bag);
	mlx_destroy_image(data->mlx_ptr, data->img.img_door);
	destroy_map(data);
	free(data->mlx_ptr);
	return ;
}
