/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkurkela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:48:20 by vkurkela          #+#    #+#             */
/*   Updated: 2019/10/22 15:05:13 by vkurkela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int lower;

	if (c > 64 && c < 91)
	{
		lower = c + 32;
		return (lower);
	}
	else
		return (c);
}