/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_deci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:50:25 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 16:47:05 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		left_handler_deci(t_struct *node, int len, char *strdata)
{
	if (check_sign_len(node) == 1)
		len += 1;
	sign_handler(node);
	ft_putstr_count(strdata, node);
	while (node->width-- > len)
		ft_putchar_count(' ', node);
}

static void		right_handler_deci(t_struct *node, int len, char *strdata)
{
	if (check_sign_len(node) == 1)
		len += 1;
	if (node->padding == 1 && node->dot == 0)
		sign_handler(node);
	while (node->width > len)
	{
		if (node->dot == 0 && node->padding == 1)
			ft_putchar_count('0', node);
		else
			ft_putchar_count(' ', node);
		node->width--;
	}
	if (node->padding == 0 || (node->padding == 1 && node->dot == 1))
		sign_handler(node);
	ft_putstr_count(strdata, node);
}

static intmax_t	check_sign(intmax_t data, t_struct *node)
{
	if (data >= 0)
		node->sign = '+';
	if (data < 0)
	{
		data = -data;
		node->sign = '-';
	}
	if (node->space == 1 && node->plus == 0 && node->sign != '-')
		node->sign = ' ';
	return (data);
}

void			get_deci(va_list *pointer, t_struct *node)
{
	intmax_t	data;
	char		*strdata;
	int			len;

	data = get_data_deci(pointer, node);
	data = check_sign(data, node);
	if (data == 0)
	{
		handle_zero_d(node);
		return ;
	}
	strdata = ft_itoa(data);
	if (node->precision > 0)
		strdata = precision_filter_d(strdata, node);
	len = ft_strlen(strdata);
	if (node->left_justified == 0)
		right_handler_deci(node, len, strdata);
	else
		left_handler_deci(node, len, strdata);
	free(strdata);
}

void			get_unsigned(va_list *pointer, t_struct *node)
{
	uintmax_t	data;
	char		*strdata;
	int			len;

	data = get_data_unsigned(pointer, node);
	if (data == 0)
	{
		handle_zero_o(node);
		return ;
	}
	strdata = ft_itoa(data);
	if (node->precision > 0)
		strdata = precision_filter_d(strdata, node);
	len = ft_strlen(strdata);
	if (node->left_justified == 0)
		right_handler_deci(node, len, strdata);
	else
		left_handler_deci(node, len, strdata);
	free(strdata);
}
