/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:32:11 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 14:56:33 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_param(va_list args, t_flag *t)
{
	int	len;

	len = 0;
	if (t->type == 'c')
		len = ft_parse_char(va_arg(args, int), t);
	else if (t->type == 's')
		len = ft_parse_string(va_arg(args, char *), t);
	else if (t->type == 'p')
		len = ft_parse_pointer(va_arg(args, unsigned long), t);
	else if (t->type == 'd' || t->type == 'i')
		len = ft_parse_int(va_arg(args, int), t);
	else if (t->type == 'u')
		len = ft_parse_uint(va_arg(args, unsigned int), t);
	else if (t->type == 'x')
		len = ft_parse_hex(va_arg(args, unsigned int), t, 0);
	else if (t->type == 'X')
		len = ft_parse_hex(va_arg(args, unsigned int), t, 1);
	else if (t->type == '%')
		len = ft_parse_per(t);
	return (len);
}
