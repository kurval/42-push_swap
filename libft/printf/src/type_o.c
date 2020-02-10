/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:11:41 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 17:50:54 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	flag_oct4(t_info *info, char flag)
{
	if (info->minus)
	{
		!(info->nb && info->output_u == 0) ?\
		ft_itoa_baseb(info->output_u, info->base, info->bytes, flag) : 0;
		if (info->width > info->precision && info->precision > info->len)
			put_spaces(info->width, info->precision, info->bytes);
		else
			put_spaces(info->width, info->len, info->bytes);
		return ;
	}
	if (info->nb && info->output_u == 0)
		return ;
	ft_itoa_baseb(info->output_u, info->base, info->bytes, flag);
}

static void	flag_oct3(t_info *info, char flag)
{
	if (info->hash && flag != 'b')
	{
		info->output_u != 0 ? ft_putcharb('0', info->bytes) : 0;
		info->hash && info->output_u == 0 &&\
		(info->nb == -1 || info->nb == -2) ?\
		ft_putcharb('0', info->bytes) : 0;
	}
	flag_oct4(info, flag);
}

static void	flag_oct2(t_info *info, char flag)
{
	info->width && !info->zero && !info->minus && !info->precision ?\
	put_spaces(info->width, info->len, info->bytes) : 0;
	if (info->width && info->precision && !info->minus)
	{
		if (info->width > info->precision && info->precision > info->len)
			put_spaces(info->width, info->precision, info->bytes);
		else if (info->width > info->precision && info->width > info->len)
			put_spaces(info->width, info->len, info->bytes);
	}
	info->width && info->zero &&\
	!info->precision && !info->minus ?\
	put_zeros(info->width, &info->len, info->bytes) : 0;
	info->precision || info->zero ?\
	put_zeros(info->precision, &info->len, info->bytes) : 0;
	flag_oct3(info, flag);
}

void		flag_oct(va_list args, t_info *info, char flag)
{
	typecast_u(args, info);
	info->base = (flag == 'o') ? 8 : 2;
	info->nbr = ft_itoa_base(info->output_u, info->base);
	info->len = (flag == 'o') ? ft_strlen(info->nbr) : 8;
	free(info->nbr);
	(info->hash && info->output_u != 0) ? info->len += 1 : info->len;
	info->nb && info->output_u == 0 ? info->len = 0 : 0;
	info->nb && info->output == 0 && info->hash ?\
	info->len = 1 : 0;
	flag_oct2(info, flag);
}
