/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:28:21 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/06 16:36:14 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../../libft.h"
# include <stdarg.h>

typedef struct	s_info
{
	int			i;
	int			*bytes;
	int			len;
	int			plus;
	int			minus;
	int			hash;
	int			space;
	int			zero;
	int			nb;
	int			width;
	char		length;
	int			precision;
	int			sign;
	char		*nbr;
	long double	output_f;
	intmax_t	output;
	uintmax_t	output_u;
	int			dot;
	char		flag;
	int			base;
}				t_info;

int				ft_printf(const char *format, ...);
void			init_info(t_info *info);
void			parser(t_info *info, const char *str, va_list args);
void			parse_h(va_list args, const char *str, t_info *info);
void			parse_l(va_list args, const char *str, t_info *info);
void			parse_hh(va_list args, const char *str, t_info *info);
void			parse_ll(va_list args, const char *str, t_info *info);
void			parse_f(va_list args, const char *str, t_info *info);
void			flag_int(va_list args, t_info *info);
void			flag_char(va_list args, t_info *info);
void			flag_str(va_list args, t_info *info);
void			flag_uint(va_list args, t_info *info);
void			flag_oct(va_list args, t_info *info, char flag);
void			flag_hex(va_list args, t_info *info, char flag);
void			flag_ptr(va_list args, t_info *info, char flag);
void			flag_float(va_list args, t_info *info);
void			flag_percent(t_info *info);
void			width(t_info *info, const char *str, va_list args);
void			precision(t_info *info, const char *str, va_list args);
void			typecast_f(va_list args, t_info *info);
void			typecast_int(va_list args, t_info *info);
void			typecast_u(va_list args, t_info *info);
void			flag_arr(va_list args, t_info *info);
void			flag_str_len(va_list args, t_info *info);
void			flag_num_len(va_list args, t_info *info);

#endif
