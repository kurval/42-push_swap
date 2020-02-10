/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:10:26 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/02 19:29:04 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		width(t_info *info, const char *str, va_list args)
{
	if (str[info->i] != '\0' && (str[info->i] == '*' || \
				(str[info->i] >= '0' && str[info->i] <= '9')))
	{
		if (str[info->i] == '*' || str[info->i + 1] == '*')
		{
			info->width = va_arg(args, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
			info->i = (str[info->i + 1]) == '*' ? info->i + 2 : info->i + 1;
		}
		else
		{
			info->i = (str[info->i] == '0') ? info->i + 1 : info->i;
			info->width = ft_atoi(&str[info->i]);
			while (str[info->i] >= '0' && str[info->i] <= '9')
				info->i += 1;
		}
	}
	info->i -= 1;
	parser(info, str, args);
}
