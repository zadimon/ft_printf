/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:37:09 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 14:45:23 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_zsp(char c, int width, int minus)
{
	int	i;

	i = 0;
	while (i < width - minus)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

int	ft_print_string(char *s, int size)
{
	int	i;

	i = 0;
	if (size >= 0)
	{
		while (i < size)
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_parse_string(char *s, t_flag *t)
{
	int		i;
	char	c;
	char	*str;

	c = ' ';
	if (t->zero == 1)
		c = '0';
	if (!(s))
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	if (t->precision < 0 || t->precision > (int)ft_strlen(str))
		t->precision = (int)ft_strlen(str);
	if (t->minus == 1)
	{
		i = ft_print_string(str, t->precision);
		i += ft_print_zsp(c, t->width, i);
	}
	else
	{
		i = ft_print_zsp(c, t->width, t->precision);
		i += ft_print_string(str, t->precision);
	}
	free(str);
	return (i);
}

int	ft_parse_char(char c, t_flag *t)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (t->minus == 1)
	{
		ft_putchar_fd(c, 1);
		i = ft_print_zsp(' ', t->width, 1);
	}
	else
	{
		i = ft_print_zsp(' ', t->width, 1);
		ft_putchar_fd(c, 1);
	}
	return (i + 1);
}
