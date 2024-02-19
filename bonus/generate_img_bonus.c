/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:59:32 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/19 14:39:39 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// t_model     define_model(char c)
// {
//     if (c == '1')
// 		return (WALL);
// 	if (c == 'C')
// 		return (COLLECTABLE);
// 	if (c == 'P')
// 		return (PLAYER);
// 	if (c == 'E')
// 		return (EXIT);
//     return (FLOOR);
// }https://github.com/andersonhsporto/ft-so_long/blob/main/source_bonus/0-map/map_update_bonus.c


// void	print_map_string(t_game *data)
// {
// 	char	*string;
    
//     data->move++;
// 	string = ft_itoa(data->move);
// 	if (count_line_maap(data->map[1]) < 9)
// 	{
// 		mlx_string_put(data->mlx_ptr, data->mlx_win, 4,
// 			(count_line_maap(data->map[1]) * 50) + 14, 0xFFFFFF, "Movements: ");
// 		mlx_string_put(data->mlx_ptr, data->mlx_win, 68,
// 			(count_line_maap(data->map[1]) * 50) + 14, 0xFFFFFF, string);
// 	}
// 	else
// 	{
// 		mlx_string_put(data->mlx_ptr, data->mlx_win,
// 			((count_line_maap(data->map[1])- 4) / 2) * 50),
// 			((count_line_maap(data->map[1])* 50 )+ 12, 0xFFFFFF, "Movements: ");
// 		mlx_string_put(data->mlx_ptr, data->mlx_win,
// 			((count_line_maap(data->map[1])- 4) / 2) * 50 + 100,
// 			(count_line_maap(data->map[1]) * 50) + 12, 0xFFFFFF, string);
// 	}
// 	free(string);
// 	string = NULL;
// 	return ;
// }

void print_map_string(t_game *data)
{
    char *string;
    
    data->move++;
    string = ft_itoa(data->move);
    if (count_line_maap(data->map[1]) < 9)
    {
        mlx_string_put(data->mlx_ptr, data->mlx_win, 4,
            (count_line_maap(data->map[1]) * 50) + 14, 0xFFFFFF, "Movements: ");
        mlx_string_put(data->mlx_ptr, data->mlx_win, 68,
            (count_line_maap(data->map[1]) * 50) + 14, 0xFFFFFF, string);
    }
    else
    {
        mlx_string_put(data->mlx_ptr, data->mlx_win,
            ((count_line_maap(data->map[1]) - 4) / 2) * 50,
            (count_line_maap(data->map[1]) * 50) + 12, 0xFFFFFF, "Movements: ");
        mlx_string_put(data->mlx_ptr, data->mlx_win,
            ((count_line_maap(data->map[1]) - 4) / 2) * 50 + 100,
            (count_line_maap(data->map[1]) * 50) + 12, 0xFFFFFF, string);
    }
    free(string);
    string = NULL;
    return;
}

void	delay(int milliseconds)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < pause)
	{
		now = clock();
	}
	return ;
}

// void    *animation_wall(t_game *data)
// {
//     int    i;

//     i = 0;

//     while (i < 100)
//     {
//         updapte_img_wall(data, "../assets/fire2.xpm");
//         delay(500);
//          updapte_img_wall(data, "../assets/fire3.xpm");
//          delay(500);
//         //  updapte_img_wall(data, "../assets/fire.xpm");
//          i++;
//     }

//     return (NULL);
// }

// void *animation_wall_thread(void *args) {
//     AnimationArgs *anim_args = (AnimationArgs *)args;
//     t_game *data = anim_args->data;
//     int duration_ms = anim_args->duration_ms;

//     int i = 0;
//     while (1) {
//         updapte_img_wall(data, "../assets/fire2.xpm");
//         delay(duration_ms);
//         updapte_img_wall(data, "../assets/fire3.xpm");
//         delay(duration_ms);
//         i++;
//         // Ajoutez ici d'autres étapes d'animation si nécessaire
//     }

//     return NULL;
// }

int animation_wall(t_game *data)
{
   
    
    static int i = 0;
    while (i < 20) 
    {
        if ((i % 2) == 0)
        {
             updapte_img_wall(data, "../assets/fire.xpm");
        delay(100);
        init_maap(data);
        }
       
        else 
        {
            updapte_img_wall(data, "../assets/fire3.xpm");
            delay(100);
            init_maap(data);
        }
             // Pause de 500 millisecondes (500000 microsecondes)
        // Pause de 500 millisecondes (500000 microsecondes)
        i++;
    }
 
      
    return (0);
}


