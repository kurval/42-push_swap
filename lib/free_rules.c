/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:40:35 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/16 19:42:31 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void    free_rules(char **rules)
{
    int i;

    i = 0;
    while (rules[i])
    {
        free(rules[i]);
        i++;
    }
}