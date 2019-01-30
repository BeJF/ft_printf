/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:00:01 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 20:07:55 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	make_struct(t_struct *node)
{
	node->dot = 0;
	node->precision = 0;
	node->left_justified = 0;
	node->width = 0;
	node->alternate = 0;
	node->padding = 0;
	node->space = 0;
	node->plus = 0;
	node->z = 0;
	node->j = 0;
	node->ll = 0;
	node->l = 0;
	node->hh = 0;
	node->h = 0;
	node->printed = 0;
	node->upc = 0;
	node->pointer = 0;
}

static void	send_types_2(va_list *pointer, t_struct *node)
{
	if (node->type == 'C')
		handle_unicode_c(pointer, node);
	else if (node->type == 'd' || node->type == 'i')
		get_deci(pointer, node);
	else if (node->type == 'u')
		get_unsigned(pointer, node);
	else if (node->type == 'o')
		ft_global_octa(pointer, node);
	else if (node->type == 'x')
		ft_global_hexa(pointer, node);
	else
		get_random(node);
}

static void	send_types(va_list *pointer, t_struct *node)
{
	convert(node);
	if (node->type == 's')
	{
		if (node->l == 1)
			handle_unicode_str(pointer, node);
		else
			get_str(pointer, node);
	}
	else if (node->type == 'S')
		handle_unicode_str(pointer, node);
	else if (node->type == 'c')
	{
		if (node->l == 1)
			handle_unicode_c(pointer, node);
		else
			get_char(pointer, node);
	}
	else
		send_types_2(pointer, node);
}

static int	operations(const char *str, t_struct *node, va_list *pointer)
{
	int printed;

	printed = 0;
	while (*str != '\0')
	{
		make_struct(node);
		while (*str != '%' && *str != '\0')
		{
			ft_putchar_count(*str, node);
			str++;
		}
		if (*str == '%')
			str++;
		if (*str == '\0')
			return (printed += node->printed);
		check_length(str, node);
		check_flags(&str, node);
		send_types(pointer, node);
		printed += node->printed;
		if (*str != '\0')
			str++;
	}
	return (printed);
}

int			ft_printf(const char *str, ...)
{
	va_list		pointer;
	int			printed;
	t_struct	*node;

	va_start(pointer, str);
	node = (t_struct*)malloc(sizeof(t_struct));
	printed = operations(str, node, &pointer);
	free(node);
	va_end(pointer);
	return (printed);
}
