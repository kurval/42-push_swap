/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:39:12 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 17:50:18 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	flag_percent(t_info *info)
{
	info->len = 1;
	info->zero && !info->minus ?\
	put_zeros(info->width, &info->len, info->bytes) : 0;
	info->width && !info->zero && !info->minus ?\
		put_spaces(info->width, 1, info->bytes) : 0;
	if (info->minus)
	{
		ft_putcharb('%', info->bytes);
		put_spaces(info->width, 1, info->bytes);
		return ;
	}
	ft_putcharb('%', info->bytes);
}
