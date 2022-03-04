/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:23:05 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 18:42:04 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mod_numcount(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_mod_itoa(int n)
{
	char	*num;
	int		count;
	int		neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	count = ft_mod_numcount(n);
	num = malloc(sizeof(*num) * (count + 1));
	if (!(num))
		return (0);
	num[count] = '\0';
	while (count - 1 >= 0)
	{
		num[count - 1] = neg * (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (num);
}

int	ft_parse_int_zflag(int i, char *s, t_flag *t)
{
	int	len;
	int	n;

	len = 0;
	n = 0;
	if (i < 0)
		n = 1;
	if (i < 0)
		len += ft_print_string("-", -1);
	len += ft_print_zsp('0', t->width, ft_strlen(s) + n);
	len += ft_print_string(s, -1);
	return (len);
}

int	ft_parse_int_part_two(int i, char *s, t_flag *t)
{
	int	n;
	int	len;

	len = 0;
	n = 0;
	if (i < 0)
		n = 1;
	if (t->minus == 0)
		len += ft_print_zsp(' ', t->width, t->precision + n);
	if (i < 0)
		len += ft_print_string("-", -1);
	len += ft_print_zsp('0', t->precision, ft_strlen(s));
	len += ft_print_string(s, -1);
	if (t->minus == 1)
		len += ft_print_zsp(' ', t->width, t->precision + n);
	return (len);
}

int	ft_parse_int(int i, t_flag *t)
{
	char	*s;
	int		len;

	if (t->precision == 0 && i == 0)
		s = ft_strdup("\0");
	else
		s = ft_mod_itoa(i);
	if (t->precision < 0 && t->zero == 1)
	{
		len = ft_parse_int_zflag(i, s, t);
		free(s);
		return (len);
	}
	if (t->precision < (int)ft_strlen(s))
		t->precision = ft_strlen(s);
	len = ft_parse_int_part_two(i, s, t);
	free(s);
	return (len);
}
