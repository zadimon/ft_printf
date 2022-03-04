/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:37:58 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 17:32:35 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_digit(const char *s, int i, t_flag *t)
{
	if (t->star == 1)
		t->width = 0;
	t->width = (t->width * 10) + (s[i] -'0');
}

void	ft_flag_width(t_flag *t, va_list args)
{
	t->star = 1;
	t->width = va_arg(args, int);
	if (t->width < 0)
	{
		t->minus = 1;
		t->width = t->width * -1;
		t->zero = 0;
	}
}

void	ft_flag_minus(t_flag *t)
{
	t->minus = 1;
	t->zero = 0;
}

int	ft_flag_precision(const char *s, int i, t_flag *t, va_list args)
{
	i++;
	if (s[i] == '*')
	{
		t->precision = va_arg(args, int);
		i++;
	}
	else
	{
		t->precision = 0;
		while (ft_isdigit(s[i]))
		{
			t->precision = (t->precision * 10) + (s[i] - '0');
			i++;
		}
	}
	return (i);
}
