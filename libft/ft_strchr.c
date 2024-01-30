/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:54:34 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/04 09:48:30 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	size_t	i;
	char	*p;
	char	search;

	i = 0;
	p = (char *)string;
	search = (char)searchedChar;
	while (p[i] != '\0')
	{
		if (p[i] == search)
		{
			return (&p[i]);
		}
		i++;
	}
	if (p[i] == search)
	{
		return (&p[i]);
	}
	if (search == '\0')
		return (NULL);
	return (0);
}
