/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:37:26 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 18:27:22 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numcount_for_hex(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*ft_uitoa_for_hex(unsigned int n, int cap)
{
	char	*num;
	int		count;

	count = ft_numcount_for_hex(n);
	num = malloc(sizeof(*num) * (count + 1));
	if (!(num))
		return (0);
	num[count] = '\0';
	while (count - 1 >= 0)
	{
		if (n % 16 < 10)
			num[count - 1] = (n % 16) + '0';
		else if (cap == 1)
			num[count - 1] = (n % 16) + 55;
		else
			num[count - 1] = (n % 16) + 87;
		n /= 16;
		count--;
	}
	return (num);
}

int	ft_parse_hex_part_two(char *s, t_flag *t)
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

int	ft_parse_hex(unsigned int i, t_flag *t, int cap)
{
	char	*s;
	int		len;

	len = 0;
	if (t->precision == 0 && i == 0)
		s = ft_strdup("\0");
	else
		s = ft_uitoa_for_hex(i, cap);
	if (t->precision < 0 && t->zero == 1)
	{
		len += ft_print_zsp('0', t->width, ft_strlen(s));
		len += ft_print_string(s, -1);
		free(s);
		return (len);
	}
	if (t->precision < (int)ft_strlen(s))
		t->precision = ft_strlen(s);
	len += ft_parse_hex_part_two(s, t);
	free(s);
	return (len);
}
