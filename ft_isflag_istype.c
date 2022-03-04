/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag_istype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:18:14 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 18:25:15 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(int c)
{
	unsigned char	s;

	s = (unsigned char)c;
	if (s == '-' || s == '0' || s == '*' || s == '.')
		return (1);
	return (0);
}

int	ft_istype(int c)
{
	unsigned char	s;

	s = (unsigned char)c;
	if (s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i'
		|| s == 'u' || s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}
