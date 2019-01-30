/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:50:42 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/05 13:31:41 by jfinet           ###   ########.fr       */
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

static int	check_sign(t_struct *node)
{
	if (node->plus == 1 && node->sign == '+')
		return (1);
	if (node->space == 1 && node->plus == 0)
		return (1);
	return (0);
}

static void	handle_plus(t_struct *node)
{
	if (node->plus == 1 && node->sign == '+')
		ft_putchar_count('+', node);
	if (node->space == 1 && node->plus == 0)
		ft_putchar_count(' ', node);
}

void		handle_zero_d(t_struct *node)
{
	int len;

	len = 1;
	if (node->dot == 1 && node->precision == 0)
		len = 0;
	if (node->precision > 0)
		len = node->precision;
	len += check_sign(node);
	if (node->padding == 1 && node->dot == 0)
		handle_plus(node);
	if (node->left_justified == 0)
		put_width(node, len);
	if (node->padding == 0 || node->dot == 1)
		handle_plus(node);
	while (node->precision-- > 0)
		ft_putchar_count('0', node);
	if (node->dot == 0)
		ft_putchar_count('0', node);
	if (node->left_justified == 1)
		put_width(node, len);
}
