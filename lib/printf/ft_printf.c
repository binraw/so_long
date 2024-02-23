/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:12 by rtruvelo          #+#    #+#             */
/*   Updated: 2023/12/04 09:48:00 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(va_list ap, int c)
{
	int	print_len;
	int	count;

	count = 0;
	print_len = 0;
	if (c == 'c')
		print_len += ft_printf_char(va_arg(ap, int));
	else if (c == 's')
		print_len += ft_printf_str(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		print_len += ft_printf_num(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		print_len += ft_printf_hexa(va_arg(ap, unsigned int), c);
	else if (c == 'u')
		print_len += ft_printf_num_unsigned(va_arg(ap, unsigned int));
	else if (c == '%')
		print_len += write(1, "%", 1);
	else if (c == 'p')
		print_len += ft_printf_putmem(va_arg(ap, unsigned long int), count);
	else
	{
		print_len += write(1, "%", 1);
		print_len += write(1, &c, 1);
	}
	return (print_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	if (!s)
		return (-1);
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (-1);
			print_len += ft_printf_format(ap, s[i + 1]);
			i = i + 2;
		}
		else
			print_len += write(1, &s[i++], 1);
	}
	va_end(ap);
	return (print_len);
}
