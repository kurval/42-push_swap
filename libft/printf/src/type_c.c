/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:47:19 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/05 10:45:17 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	flag_char(va_list args, t_info *info)
{
	char output;

	output = (char)va_arg(args, int);
	info->width && !info->minus ? put_spaces(info->width, 1, info->bytes) : 0;
	if (info->minus)
	{
		ft_putcharb(output, info->bytes);
		put_spaces(info->width, 1, info->bytes);
		return ;
	}
	ft_putcharb(output, info->bytes);
}
