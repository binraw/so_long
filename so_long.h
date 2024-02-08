/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:06 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/08 14:50:38 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#	include "./mlx.h"



#	include "get_next_line.h"

typedef struct img_s
{
	int		height;
	int		width;
	void *img_player;  // Pointeur vers l'image
	void *img_background;  // Pointeur vers l'image
	void *img_wall;  // Pointeur vers l'image
    char *player;     // Données de l'image
	char *background;     // Données de l'image
	char *wall;     // Données de l'image
}				t_img;


typedef struct game_s
{
	void	*mlx_ptr;
	void	*mlx_win;

	int		width;
	int		height;
	
	t_img	img;

	
}	t_game;



// void print_img(t_game *data);
int set_img(t_game *data);
void	print_img(t_game *data, void *img, int x, int y);





#endif
