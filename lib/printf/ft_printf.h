/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtruvelo <rtruvelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:52:25 by rtruvelo          #+#    #+#             */
/*   Updated: 2024/02/23 12:48:32 by rtruvelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

int					ft_printf_hexa(unsigned int n, char format);
int					ft_printf_format(va_list ap, int c);
int					ft_printf(const char *s, ...);
int					ft_printf_str(char *str);
int					ft_printf_num(int n);
int					ft_printf_char(int c);
unsigned long int	ft_printf_putmem(unsigned long int n, int count);
unsigned int		ft_printf_num_unsigned(unsigned int n);


#endif