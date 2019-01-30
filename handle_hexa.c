/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:37:42 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 20:16:46 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	left_handler_hexa(t_struct *node, int len, char *strdata)
{
	if (node->alternate == 1)
	{
		if (node->dot == 0 && node->upc == 0)
			ft_putstr_count("0x", node);
		if (node->dot == 0 && node->upc == 1)
			ft_putstr_count("0X", node);
	}
	ft_putstr_count(strdata, node);
	while (node->width-- > len)
		ft_putchar_count(' ', node);
}

static void	right_handler_hexa(t_struct *node, int len, char *strdata)
{
	if (node->alternate == 1 && node->padding == 1)
	{
		if (node->dot == 0 && node->upc == 0)
			ft_putstr_count("0x", node);
		if (node->dot == 0 && node->upc == 1)
			ft_putstr_count("0X", node);
	}
	while (node->width-- > len)
	{
		if (node->dot == 0 && node->padding == 1)
			ft_putchar_count('0', node);
		else
			ft_putchar_count(' ', node);
	}
	if (node->alternate == 1 && node->padding == 0)
	{
		if (node->dot == 0 && node->upc == 0)
			ft_putstr_count("0x", node);
		if (node->dot == 0 && node->upc == 1)
			ft_putstr_count("0X", node);
	}
	ft_putstr_count(strdata, node);
}

void		ft_global_hexa(va_list *pointer, t_struct *node)
{
	uintmax_t	data;
	int			len;
	char		*strdata;

	data = get_data_unsigned(pointer, node);
	if (data == 0)
	{
		handle_zero_x(node);
		return ;
	}
	if (data > 0)
		node->sign = '+';
	strdata = ft_itoa_hexa(data, node->upc);
	if (node->dot == 1)
		strdata = precision_filter_xo(strdata, node);
	len = ft_strlen(strdata);
	if (node->alternate == 1 && node->sign == '+' && node->dot == 0)
		len += 2;
	if (node->left_justified == 0)
		right_handler_hexa(node, len, strdata);
	else
		left_handler_hexa(node, len, strdata);
	free(strdata);
}
