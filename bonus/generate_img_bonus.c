/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:59:32 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/21 12:38:14 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_map_string(t_game *data)
{
	char	*string;

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
	return ;
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

int	animation_wall(t_game *data)
{
	static int	i = 0;

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
		i++;
	}
	return (0);
}

char	**dup_map(t_game *data)
{
	int		y;
	char	**duplicate;

	y = 0;
	duplicate = (char **)malloc(sizeof(char *) * (data->numb_line));
	if (!duplicate)
	{
		return (NULL);
	}
	while (y < data->numb_line)
	{
		duplicate[y] = ft_strdup_get(data->map[y]);
		y++;
	}
	return (duplicate);
}

void	good_path(t_game *data, char **dup, int i, int y)
{
	if (dup[y][i] != '1')
	{
		if (dup[y][i] == 'C')
			data->numb_collectible--;
		else if (dup[y][i] == 'E')
		{
			data->numb_exit--;
			dup[y][i] = '1';
			return ;
		}
		dup[y][i] = 'P';
	}
}
