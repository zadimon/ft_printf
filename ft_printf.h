/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:36:26 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/05/13 18:42:16 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_flag
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	star;
}		t_flag;

int		ft_printf(const char *format, ...);
int		ft_parse_input(const char *input, va_list args);
int		ft_parse_flag(const char *s, int i, t_flag *t, va_list args);
t_flag	ft_flag_init(void);
int		ft_istype(int c);
int		ft_isflag(int c);
int		ft_flag_precision(const char *s, int i, t_flag *t, va_list args);
void	ft_flag_minus(t_flag *t);
void	ft_flag_width(t_flag *t, va_list args);
void	ft_flag_digit(const char *s, int i, t_flag *t);
int		ft_parse_param(va_list args, t_flag *t);
int		ft_parse_char(char c, t_flag *t);
int		ft_parse_string(char *s, t_flag *t);
int		ft_print_string(char *s, int size);
int		ft_print_zsp(char c, int width, int minus);
int		ft_parse_pointer(unsigned long l, t_flag *t);
char	*ft_ultoa(unsigned long l);
int		ft_parse_int(int i, t_flag *t);
int		ft_mod_numcount(int n);
char	*ft_mod_itoa(int n);
int		ft_parse_int_zflag(int i, char *s, t_flag *t);
int		ft_parse_int_part_two(int i, char *s, t_flag *t);
int		ft_parse_uint(unsigned int i, t_flag *t);
char	*ft_uitoa(unsigned int n);
int		ft_parse_uint_part_two(char *s, t_flag *t);
int		ft_numcount_for_ui(unsigned int n);
int		ft_parse_hex(unsigned int i, t_flag *t, int cap);
int		ft_parse_hex_part_two(char *s, t_flag *t);
char	*ft_uitoa_for_hex(unsigned int n, int cap);
int		ft_numcount_for_hex(unsigned int n);
int		ft_parse_per(t_flag *t);

#endif
