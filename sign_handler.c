/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 20:27:52 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/03 20:28:50 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_sign_len(t_struct *node)
{
	if (node->plus == 1 && node->sign == '+')
		return (1);
	if (node->plus != 1 && node->sign == ' ')
		return (1);
	if (node->sign == '-')
		return (1);
	else
		return (0);
}

void	sign_handler(t_struct *node)
{
	if (node->plus == 1 && node->sign == '+')
		ft_putchar_count('+', node);
	if (node->plus == 0 && node->sign == ' ')
		ft_putchar_count(' ', node);
	if (node->sign == '-')
		ft_putchar_count('-', node);
}
