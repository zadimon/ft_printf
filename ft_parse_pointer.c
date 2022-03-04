/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:29:04 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 14:47:08 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa(unsigned long l)
{
	int				count;
	unsigned long	tmp;
	char			*s;

	count = 0;
	tmp = l;
	while (tmp != 0)
	{
		tmp /= 16;
		count++;
	}
	s = malloc(sizeof(*s) * (count + 1));
	if (!(s))
		return (0);
	s[count] = '\0';
	while (count - 1 >= 0)
	{
		if (l % 16 < 10)
			s[count - 1] = l % 16 + '0';
		else
			s[count - 1] = l % 16 + 87;
		l /= 16;
		count--;
	}
	return (s);
}

int	ft_parse_pointer(unsigned long l, t_flag *t)
{
	char			*s;
	int				len;

	len = 0;
	if (l == 0)
	{
		s = ft_strdup("\0");
		if (t->precision < 0)
			t->precision = 1;
	}
	else
		s = ft_ultoa(l);
	if (t->precision < (int)ft_strlen(s))
		t->precision = ft_strlen(s);
	if (t->minus == 0)
		len += ft_print_zsp(' ', t->width, 2 + t->precision);
	len += ft_print_string("0x", -1);
	len += ft_print_zsp('0', t->precision, ft_strlen(s));
	len += ft_print_string(s, -1);
	if (t->minus == 1)
		len += ft_print_zsp(' ', t->width, 2 + t->precision);
	free(s);
	return (len);
}
