/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 18:23:37 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/05 17:54:36 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi_up(const char ***str)
{
	unsigned long	nb;

	nb = 0;
	if (***str == '0')
	{
		(**str)++;
		return (0);
	}
	if (***str < '0' || ***str > '9')
		return (0);
	while (***str >= '0' && ***str <= '9')
	{
		nb = (nb * 10) + (***str - '0');
		(**str)++;
		if (nb > 9223372036854775807)
			return (-1);
	}
	return ((int)nb);
}
