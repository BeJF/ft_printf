/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:53:14 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 16:49:06 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	get_data_deci(va_list *pointer, t_struct *node)
{
	intmax_t data;

	if (node->z == 1)
		data = (ssize_t)va_arg(*pointer, intmax_t);
	else if (node->j == 1)
		data = va_arg(*pointer, intmax_t);
	else if (node->ll == 1)
		data = (long long int)va_arg(*pointer, intmax_t);
	else if (node->l == 1)
		data = (long int)va_arg(*pointer, intmax_t);
	else if (node->h == 1)
		data = (short int)va_arg(*pointer, intmax_t);
	else if (node->hh == 1)
		data = (char)va_arg(*pointer, intmax_t);
	else
		data = (int)va_arg(*pointer, intmax_t);
	return (data);
}

uintmax_t	get_data_unsigned(va_list *pointer, t_struct *node)
{
	uintmax_t data;

	if (node->z == 1)
		data = (size_t)va_arg(*pointer, uintmax_t);
	else if (node->j == 1)
		data = va_arg(*pointer, uintmax_t);
	else if (node->ll == 1)
		data = (unsigned long long)va_arg(*pointer, uintmax_t);
	else if (node->l == 1)
		data = (unsigned long int)va_arg(*pointer, uintmax_t);
	else if (node->h == 1)
		data = (unsigned short)va_arg(*pointer, uintmax_t);
	else if (node->hh == 1)
		data = (unsigned char)va_arg(*pointer, uintmax_t);
	else
		data = (unsigned int)va_arg(*pointer, uintmax_t);
	return (data);
}

void		get_random(t_struct *node)
{
	if (node->left_justified == 1)
		ft_putchar_count(node->type, node);
	while (node->width-- > 1)
		ft_putchar_count(' ', node);
	if (node->left_justified == 0)
		ft_putchar_count(node->type, node);
}
