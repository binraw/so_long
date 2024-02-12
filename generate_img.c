/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:59:32 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/12 14:08:15 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_model     define_model(char c)
{
    if (c == '1')
		return (WALL);
	if (c == 'C')
		return (COLLECTABLE);
	if (c == 'P')
		return (PLAYER);
	if (c == 'E')
		return (EXIT);
    return (FLOOR);
}