/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:54:18 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/05 13:29:09 by jfinet           ###   ########.fr       */
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

static int	check_alternate(t_struct *node)
{
	if (node->alternate == 1 && node->pointer == 1)
		return (2);
	return (0);
}

static void	handle_alternate(t_struct *node)
{
	if (node->alternate == 1 && node->pointer == 1)
		ft_putstr_count("0x", node);
}

void		handle_zero_x(t_struct *node)
{
	int len;

	len = 1;
	if (node->dot == 1 && node->precision == 0)
		len = 0;
	if (node->precision > 0)
		len = node->precision;
	len += check_alternate(node);
	if (node->padding == 1 && node->dot == 0)
		handle_alternate(node);
	if (node->left_justified == 0)
		put_width(node, len);
	if (node->padding == 0 || node->dot == 1)
		handle_alternate(node);
	while (node->precision-- > 0)
		ft_putchar_count('0', node);
	if (node->dot == 0)
		ft_putchar_count('0', node);
	if (node->left_justified == 1)
		put_width(node, len);
}
