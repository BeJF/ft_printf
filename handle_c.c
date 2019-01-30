/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:36:07 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 20:06:42 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_unicode_c(va_list *pointer, t_struct *node)
{
	wchar_t data;

	data = va_arg(*pointer, wchar_t);
	if (0x0000 <= data && data <= 0x007F)
		put_one_byte(data, node);
	if (0x0080 <= data && data <= 0x07FF)
		put_two_bytes(data, node);
	if (0x0800 <= data && data <= 0xFFFF)
		put_three_bytes(data, node);
	if (0x10000 <= data && data <= 0x10FFFF)
		put_four_bytes(data, node);
}

void	get_char(va_list *pointer, t_struct *node)
{
	char data;

	data = va_arg(*pointer, int);
	if (node->left_justified == 1)
		ft_putchar_count(data, node);
	while (node->width-- > 1)
		ft_putchar_count(' ', node);
	if (node->left_justified == 0)
		ft_putchar_count(data, node);
}
