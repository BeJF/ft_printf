/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:13:12 by jfinet            #+#    #+#             */
/*   Updated: 2018/08/18 16:14:30 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_count(char const *s, t_struct *node)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s++, 1);
		node->printed += 1;
	}
}
