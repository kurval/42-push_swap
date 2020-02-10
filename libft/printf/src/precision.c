/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:43:42 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 10:40:37 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	precision2(t_info *info, const char *str, va_list args)
{
	if (str[info->i] != '\0' && (str[info->i] > '0' && str[info->i] <= '9'))
	{
		info->precision = ft_atoi(&str[info->i]);
		while (str[info->i] >= '0' && str[info->i] <= '9')
			info->i += 1;
		info->nb = 0;
	}
	info->i -= 1;
	parser(info, str, args);
}

void		precision(t_info *info, const char *str, va_list args)
{
	info->i += 1;
	if (!(str[info->i] >= '0' && str[info->i] <= '9') && str[info->i] != '*')
		info->nb = -2;
	if (str[info->i] != '\0' && (str[info->i] == '*' || str[info->i] == '0'))
	{
		if (str[info->i] == '*')
		{
			info->precision = va_arg(args, int);
			info->precision == 0 ? info->nb = -1 : 0;
			info->precision < 0 ? info->precision = 0 : 0;
		}
		str[info->i] == '0' ? info->nb = -1 : 0;
		info->i += 1;
	}
	precision2(info, str, args);
}
