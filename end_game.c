#include "so_long.h"

// void    destroy_map(t_game *data)
// {
//     while (data->numb_line > 0)
// 	{
// 		free(data->map[data->numb_line]);
// 		data->numb_line--;
// 	}
// 	free(data->map[data->numb_line]);
// 	return ;
// }

void    destroy_map(t_game *data)
{
	int i;
	int y;

	i = 0;
	y = data->numb_line - 1;
	if (!data->map)
	{
		free(data->map[0]);
		return ; 
	}	
    while (y > 0)
	{
		free(data->map[y]);
		y--;
	}
	 free(data->map[y]);
	 free(data->map);
	return ;
}

void    destroy_double_char(t_game *data, char **map)
{
	int i;
	int y;

	i = 0;
	y = data->numb_line - 1;
	if (!map)
	{
		free(map[0]);
		return ; 
	}	
    while (y > 0)
	{
		free(map[y]);
		y--;
	}
	 free(map[y]);
	 free(map);
	return ;
}

int    destroy_img(t_game *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_background);
	mlx_destroy_image(data->mlx_ptr, data->img.img_bag);
	mlx_destroy_image(data->mlx_ptr, data->img.img_door);
	destroy_map(data);
	
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
