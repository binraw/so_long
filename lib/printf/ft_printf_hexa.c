/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:51:51 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/11/30 12:39:48 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(unsigned int n, char format)
{
	const char		str[] = "0123456789abcdef";
	const char		maj[] = "0123456789ABCDEF";
	int				result;

	result = 0;
	if (n >= 16)
	{
		result += ft_printf_hexa(n / 16, format);
		result += ft_printf_hexa(n % 16, format);
	}
	else
	{
		if (format == 'x')
		{
			write(1, &str[n], 1);
			result++;
		}
		if (format == 'X')
		{
			write(1, &maj[n], 1);
			result++;
		}
	}
	return (result);
}
