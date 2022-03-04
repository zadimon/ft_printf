/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:52:52 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 18:25:45 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_flag	ft_flag_init(void)
{
	t_flag	t;

	t.type = 0;
	t.width = 0;
	t.minus = 0;
	t.zero = 0;
	t.precision = -1;
	t.star = 0;
	return (t);
}

int	ft_parse_flag(const char *s, int i, t_flag *t, va_list args)
{
	while (ft_isdigit(s[i]) || ft_istype(s[i]) || ft_isflag(s[i]))
	{
		if (s[i] == '0' && t->width == 0 && t->minus == 0)
			t->zero = 1;
		if (s[i] == '.')
			i = ft_flag_precision(s, i, t, args);
		if (s[i] == '-')
			ft_flag_minus(t);
		if (s[i] == '*')
			ft_flag_width(t, args);
		if (ft_isdigit(s[i]))
			ft_flag_digit(s, i, t);
		if (ft_istype(s[i]))
		{
			t->type = s[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_parse_input(const char *input, va_list args)
{
	size_t	i;
	size_t	count;
	t_flag	t;

	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		t = ft_flag_init();
		if (input[i] == '%' && input[i + 1] != '\0')
		{
			i = ft_parse_flag(input, ++i, &t, args);
			if (ft_istype(input[i]))
				count += ft_parse_param(args, &t);
		}
		else if (input[i] != '\0')
		{
			ft_putchar_fd(input[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;
	const char	*input;

	input = ft_strdup(format);
	va_start(args, format);
	len = ft_parse_input(input, args);
	va_end(args);
	free((char *)input);
	return (len);
}
