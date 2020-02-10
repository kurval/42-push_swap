/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:04:11 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/02 19:57:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		flag_str_len(va_list args, t_info *info)
{
	char *output;

	output = va_arg(args, char*);
	info->len = ft_strlen(output);
	ft_putnbrb(info->len, info->bytes);
}

void		flag_num_len(va_list args, t_info *info)
{
	long long output;

	output = va_arg(args, int);
	info->len = ft_numlen(output);
	ft_putnbrb(info->len, info->bytes);
}
