/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:42:36 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/27 10:49:52 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int check_flag(char *first)
{
    if (!ft_strncmp_end(first, "-v", 2))
        return (1);
    else
        return (0);
}