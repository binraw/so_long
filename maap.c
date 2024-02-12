/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:51:36 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/12 13:56:52 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_maap(t_game *data, char **argv)
{
    char	**maap;
	int		y;
	int		i;

	y = 0;
	i = 0;
    maap = read_maap(argv[1]);
	if (!maap)
		return (NULL);
	
}

char **read_maap(char *file)
{
    char	**maap;
    int		i;
    int		fd;

	i = 0;
	maap = alloc_lign(file);
	if (!maap)
	{
		close(fd);
		return (NULL);
	}
		
	fd = open(file, O_RDONLY);
	
	while (i < count_line_maap(file))
	{
		maap[i] = get_next_line(fd);
		i++;
	}
	maap[i] = NULL;
	close(fd);
	
    return (maap);
}

int count_line_maap(char *file)
{
	int		count;
	int		fd;
	int 	reader;
	char	c;
	
	fd = open(file, O_RDONLY);
	count = 1;
	while(reader > 0)
	{
		reader = read(fd, &c, 1);
		if (reader < 0)
			return (-1);
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

char **alloc_lign(char *file)
{
	char	**maap;
	int		line_count;

	line_count = count_line_maap(file);
	if (line_count == 0)
		return (NULL);
	maap = malloc(sizeof(char *) * line_count + 1);
	if (!maap)
		return (NULL);
	return (maap);
	
}