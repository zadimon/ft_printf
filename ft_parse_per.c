/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:32:16 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 14:46:50 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_per(t_flag *t)
{
	int		len;
	char	c;

	len = 0;
	c = ' ';
	if (t->zero == 1)
		c = '0';
	if (t->minus == 0)
		len += ft_print_zsp(c, t->width, 1);
	len += ft_print_string("%", -1);
	if (t->minus == 1)
		len += ft_print_zsp(' ', t->width, 1);
	return (len);
}
