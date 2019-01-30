/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 21:22:01 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 20:05:27 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	right_handler_octa(t_struct *node, int len, char *strdata)
{
	while (node->width-- > len)
	{
		if (node->dot == 0 && node->padding == 1)
			ft_putchar_count('0', node);
		else
			ft_putchar_count(' ', node);
	}
	if (node->alternate == 1)
	{
		if (node->dot == 0)
			ft_putchar_count('0', node);
	}
	ft_putstr_count(strdata, node);
}

static void	left_handler_octa(t_struct *node, int len, char *strdata)
{
	if (node->alternate == 1)
	{
		if (node->dot == 0)
			ft_putchar_count('0', node);
	}
	ft_putstr_count(strdata, node);
	while (node->width-- > len)
	{
		ft_putchar_count(' ', node);
	}
}

void		ft_global_octa(va_list *pointer, t_struct *node)
{
	uintmax_t	data;
	int			len;
	char		*strdata;

	data = get_data_unsigned(pointer, node);
	if (data == 0)
	{
		handle_zero_o(node);
		return ;
	}
	strdata = ft_itoa_base(data, 8);
	if (node->dot == 1)
		strdata = precision_filter_xo(strdata, node);
	len = ft_strlen(strdata);
	if (node->dot == 0 && node->alternate == 1)
		len++;
	if (node->left_justified == 0)
		right_handler_octa(node, len, strdata);
	else
		left_handler_octa(node, len, strdata);
	free(strdata);
}
