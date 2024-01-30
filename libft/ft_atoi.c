/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:19:54 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/01/25 15:02:24 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


// static int	white_space(const char *str)
// {
// 	int		count;
// 	int		i;

// 	count = 0;
// 	i = 0;
// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 	{
// 		i++;
// 		count++;
// 	}
// 	return (count);
// }

// long	ft_atoi(const char *str)
// {
// 	long int	result;
// 	long int	resultcpy;
// 	long			sign;
// 	int				i;

// 	result = 0;
// 	sign = 1;
// 	i = 0 + white_space(str);
	
// 	if (str[i] == '-')
// 		sign = -1;
// 	if (str[i] == '+' || str[i] == '-')
// 		i++;
// 	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
// 	{
// 		resultcpy = result;
// 		result = ((result * 10) + (str[i] - 48) * sign);
		
// 		i++;
// 	}
// 	printf("%ld\n", result);
// 	return (result);
// }
long    ft_atoi(const char *s) 
{
    long    result;
    int        sign;

    result = 0;
    sign = 1; 
    while (*s == ' ' || *s == '\t' || *s == '\n' || \
            *s == '\r' || *s == '\f' || *s == '\v')
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    while (ft_isdigit(*s))
        result = result * 10 + (*s++ - '0');
		
    return (result * sign);
}