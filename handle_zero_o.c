/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:56:09 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/05 13:30:02 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_width(t_struct *node, int len)
{
	while (node->width-- > len)
	{
		if (node->padding == 1 && node->dot == 0 && node->left_justified == 0)
			ft_putchar_count('0', node);
		else
			ft_putchar_count(' ', node);
	}
}

void		handle_zero_o(t_struct *node)
{
	int len;

	len = 0;
	if (node->precision > 0)
		len = node->precision;
	if (node->precision == 0 && node->dot != 1)
		len++;
	if (node->dot == 1 && node->precision == 0 && node->alternate == 1)
		len++;
	if (node->left_justified == 0)
		put_width(node, len);
	if (node->precision == 0 && node->dot != 1)
		ft_putchar_count('0', node);
	if (node->dot == 1 && node->precision == 0 && node->alternate == 1)
		ft_putchar_count('0', node);
	while (node->precision-- > 0)
		ft_putchar_count('0', node);
	if (node->left_justified == 1)
		put_width(node, len);
}
