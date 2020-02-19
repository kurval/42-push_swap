/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:59:14 by vkurkela          #+#    #+#             */
/*   Updated: 2020/02/19 21:28:25 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	read_instructions(t_rules **rules)
{
	int		ret;
	char	*line;
	int		nbr;

	nbr = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_strlen(line) > 3)
			return (0);
		push_rules(rules, line);
		free(line);
	}
	if (ret == -1)
		return (0);
	return (1);
}
