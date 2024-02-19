/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:06 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/19 09:36:18 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


#	include "./mlx_linux/mlx.h"
#	include <X11/keysym.h>

#	include <stdlib.h>
#	include <stdio.h>
#	include "printf/ft_printf.h"
#	include "get_next_line.h"

typedef struct img_s
{
	int		height;
	int		width;
	void		*img_player;  // Pointeur vers l'image
	void		*img_background;  // Pointeur vers l'image
	void		*img_wall;  // Pointeur vers l'image
	void		*img_door;
	void		*img_bag;
	void		*img_player_right;
	char		*bag;
	char		*door;
	char		*player;
	    // Données de l'image
	char *background;     // Données de l'image
	char *wall;     // Données de l'image
}				t_img;


typedef struct game_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int	numb_line;
	int	numb_collectible;
	int	numb_exit;
	char	**map;
	int	pos_x;
	int	pos_y;
	int	move;
	int	count_left;
	int	reta_right;
	int	count_back;
	int	count_face;
	t_img	img;

	
}	t_game;


int	set_img(t_game *data);
void	print_img(t_game *data, void *img, int x, int y);
void	alloc_lign(char *file, t_game *data);
int	count_line_maap(char *file);
int	count_line(char **file);
void	read_maap(char *file, t_game *data);
int	count_collect(t_game *data);
// void init_maap(t_game *data, char **argv);
void	init_maap(t_game *data);
void	screen_model(char c, t_game *data, int i, int y);
int	key_hook(int keycode, t_game *data);
void	player_move(t_game *data, int new_y, int new_x);
void    control_move(t_game *data, int new_y, int new_x);

int	check_extension_file(char **argv);
int	check_side_wall(t_game *data);
int	check_wall_map(t_game *data);
int     format_check(t_game *data);
int	count_elem(t_game *data, char c);
int	all_check_map(t_game *data, char **argv);
int	check_side_wall(t_game *data);
int	check_number_elem(t_game *data);
int	check_content(t_game *data);
int	check_valid_map(t_game *data);
char	**dup_map(t_game *data);
int	valid_map(t_game *data, char **dup, int y);
void	good_path(t_game *data, char **dup, int i, int y);
void    screen_number_move(t_game *data);
void	destroy_img(t_game *data);
void	destroy_map(t_game *data);

#endif
