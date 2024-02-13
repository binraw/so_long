/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:51:36 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/13 12:05:53 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> 

void init_maap(t_game *data)
{
    // char	**maap;
	int		y;
	int		i;
	

	y = 0;
	i = 0;
	// printf("%d\n", i);
    // read_maap(argv[1], data);
	if (!data->map)
		return ;

	while (data->map[y])
	{
		i = 0;
		while(data->map[y][i] != '\n' && data->map[y][i])
		{
			screen_model(data->map[y][i], data, i, y);
			// printf("%d\n", i);
			i++;
		}
		// printf("%d\n", y);
		y++;
	}
	
}
void	screen_model(char c, t_game *data, int i, int y)
{
	
	if (c == '1')
	{
		print_img(data, data->img.img_wall, i, y);
		printf("%d\n", y);
		printf("%d\n", i);
	}
	if (c == '0')
	{
		print_img(data, data->img.img_background, i, y);
	}
	if (c == 'C')
	{
		print_img(data, data->img.img_bag, i, y);
	}
	if (c == 'E')
	{
		print_img(data, data->img.img_door, i, y);
	}
	if (c == 'P')
	{
		print_img(data, data->img.img_player, i, y);
	}
}

void	read_maap(char *file, t_game *data)
{
    // char	**maap;
    int		i;
    int		fd;
	int count;

	i = 0;
	fd = 0;
	count = 0;
	// printf("%d\n", i);
	// printf("%d\n", 1);
	 alloc_lign(file, data);
	if (!data->map)
	{
		close(fd);
		return ;
	}
		
	fd = open(file, O_RDONLY);
	
	count = count_line_maap(file);
	// printf("%d\n", 1);
	while ( i < count)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	

}

int count_line_maap(char *file)
{
	int		count;
	int		fd;
	int 	reader;
	char	*lign;
	
	// file = "bom";
	reader = 0;
	fd = open(file, O_RDONLY);
	count = -1;
	lign = "lign";
	while(lign != NULL)
	{
		lign = get_next_line(fd);
		free(lign);
			count++;
			
		
	}
	close(fd);
	return (count);
}



void		alloc_lign(char *file, t_game *data)
{
	// char	**maap;
	int		line_count;
	line_count = 0;
	// printf("%d\n", line_count);
	line_count = count_line_maap(file);
	// if (line_count == 0)
	// 	return (NULL);
	data->map = malloc(sizeof(char *) * line_count + 1);
	// if (!data->map)
		
}