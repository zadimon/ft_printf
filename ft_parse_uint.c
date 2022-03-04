/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:17:43 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 14:47:44 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numcount_for_ui(unsigned int n)
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

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		count;

	count = ft_numcount_for_ui(n);
	num = malloc(sizeof(*num) * (count + 1));
	if (!(num))
		return (0);
	num[count] = '\0';
	while (count - 1 >= 0)
	{
		num[count - 1] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (num);
}

int	ft_parse_uint_part_two(char *s, t_flag *t)
{
	int	len;

	len = 0;
	if (t->minus == 0)
		len += ft_print_zsp(' ', t->width, t->precision);
	len += ft_print_zsp('0', t->precision, ft_strlen(s));
	len += ft_print_string(s, -1);
	if (t->minus == 1)
		len += ft_print_zsp(' ', t->width, t->precision);
	return (len);
}

int	ft_parse_uint(unsigned int i, t_flag *t)
{
	char	*s;
	int		len;

	if (t->precision == 0 && i == 0)
		s = ft_strdup("\0");
	else
		s = ft_uitoa(i);
	if (t->precision < 0 && t->zero == 1)
	{
		len = ft_print_zsp('0', t->width, ft_strlen(s));
		len += ft_print_string(s, -1);
		free(s);
		return (len);
	}
	if (t->precision < (int)ft_strlen(s))
		t->precision = ft_strlen(s);
	len = ft_parse_uint_part_two(s, t);
	free(s);
	return (len);
}
