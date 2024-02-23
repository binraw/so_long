/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putmem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:45:03 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/11/30 12:58:33 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	ft_printf_putmem(unsigned long int n, int count)
{
	const char	str[] = "0123456789abcdef";
	int			i;

	i = 0;
	if (n == 0 && count == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (count == 0)
	{
		write(1, "0x", 2);
		i = i + 2;
	}
	if (n >= 16)
	{
		i += ft_printf_putmem(n / 16, count - 1);
		i += ft_printf_putmem(n % 16, count - 1);
	}
	else
	{
		write(1, &str[n], 1);
		i++;
	}
	return (i);
}
