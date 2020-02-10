/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:56:20 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/04 09:56:28 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	flag_ptr(va_list args, t_info *info, char flag)
{
	info->output_u = (unsigned long)va_arg(args, void*);
	info->nbr = ft_itoa_baseul(info->output_u, 16);
	info->width && !info->minus ?\
		put_spaces(info->width, ft_strlen(info->nbr) + 2, info->bytes) : 0;
	if (info->minus)
	{
		ft_putstrb("0x", info->bytes);
		!(info->nb && info->output_u == 0) ?\
		ft_itoa_baseb(info->output_u, 16, info->bytes, flag) : 0;
		put_spaces(info->width, ft_strlen(info->nbr) + 2, info->bytes);
		free(info->nbr);
		return ;
	}
	free(info->nbr);
	ft_putstrb("0x", info->bytes);
	if (info->nb && info->output_u == 0)
		return ;
	ft_itoa_baseb(info->output_u, 16, info->bytes, flag);
}
