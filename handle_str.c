/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:07:14 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 15:32:07 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	put_bytes(t_struct *node, wchar_t *data, int nb_chars)
{
	while (*data && nb_chars != 0)
	{
		if (0x0000 <= *data && *data <= 0x007F)
			put_one_byte(*data, node);
		if (0x0080 <= *data && *data <= 0x07FF)
			put_two_bytes(*data, node);
		if (0x0800 <= *data && *data <= 0xFFFF)
			put_three_bytes(*data, node);
		if (0x10000 <= *data && *data <= 0x10FFFF)
			put_four_bytes(*data, node);
		if (node->dot == 1)
			nb_chars--;
		data++;
	}
}

static int	count_char(t_struct *node, wchar_t *data)
{
	int count;

	count = 0;
	if (node->dot == 0 && node->width == 0)
		return (-1);
	while (*data && node->precision != 0)
	{
		if (0x0000 <= *data && *data <= 0x007F)
			node->precision -= 1;
		if (0x0080 <= *data && *data <= 0x07FF)
			node->precision -= 2;
		if (0x0800 <= *data && *data <= 0xFFFF)
			node->precision -= 3;
		if (0x10000 <= *data && *data <= 0x10FFFF)
			node->precision -= 4;
		if (node->precision < 0)
			break ;
		count++;
		data++;
	}
	return (count);
}

static int	count_bytes(t_struct *node, wchar_t *data, int nb_chars)
{
	int bytes;

	bytes = 0;
	while (*data && nb_chars != 0)
	{
		if (0x0000 <= *data && *data <= 0x007F)
			bytes += 1;
		if (0x0080 <= *data && *data <= 0x07FF)
			bytes += 2;
		if (0x0800 <= *data && *data <= 0xFFFF)
			bytes += 3;
		if (0x10000 <= *data && *data <= 0x10FFFF)
			bytes += 4;
		data++;
		if (node->dot == 1)
			nb_chars--;
	}
	return (bytes);
}

void		handle_unicode_str(va_list *pointer, t_struct *node)
{
	wchar_t	*data;
	int		nb_chars;
	int		bytes;

	bytes = 0;
	nb_chars = -1;
	data = va_arg(*pointer, wchar_t*);
	if (data == NULL)
	{
		ft_putstr_count("(null)", node);
		return ;
	}
	if (node->dot == 1)
		nb_chars = count_char(node, data);
	bytes = count_bytes(node, data, nb_chars);
	if (node->left_justified == 1)
		put_bytes(node, data, nb_chars);
	while (node->width-- > bytes)
		ft_putchar_count(' ', node);
	if (node->left_justified == 0)
		put_bytes(node, data, nb_chars);
}

void		get_str(va_list *pointer, t_struct *node)
{
	char	*data;
	int		len;

	data = va_arg(*pointer, char*);
	if (data == NULL)
	{
		ft_putstr_count("(null)", node);
		return ;
	}
	if (node->precision > 0 && node->dot == 1)
		data = precision_filter_str(data, node->precision);
	if (node->dot == 1 && node->precision == 0)
		data = "";
	len = ft_strlen(data);
	if (node->left_justified == 1)
		ft_putstr_count(data, node);
	while (node->width-- > len)
		ft_putchar_count(' ', node);
	if (node->left_justified == 0)
		ft_putstr_count(data, node);
}
