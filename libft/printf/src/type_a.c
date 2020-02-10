/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:04:11 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/03 10:33:53 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		flag_arr(va_list args, t_info *info)
{
	char	**output;
	int		i;

	i = -1;
	output = va_arg(args, char**);
	if (output == NULL)
	{
		ft_putstrb("(null)", info->bytes);
		return ;
	}
	while (output[++i])
	{
		ft_putstrb(output[i], info->bytes);
		ft_putcharb('\n', info->bytes);
	}
}
