/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:19:21 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 20:16:35 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		check_length(const char *str, t_struct *node)
{
	while (*str && *str != '%')
	{
		if (*str == 'l')
		{
			str++;
			if (*str == 'l')
				node->ll = 1;
			else
				node->l = 1;
		}
		if (*str == 'h')
		{
			str++;
			if (*str == 'h')
				node->hh = 1;
			else
				node->h = 1;
		}
		if (*str == 'z')
			node->z = 1;
		if (*str == 'j')
			node->j = 1;
		str++;
	}
}

static void	part_check_flags(const char *str, t_struct *node)
{
	if (*str == '+')
		node->plus = 1;
	else if (*str == ' ')
		node->space = 1;
	else if (*str == '0')
		node->padding = 1;
	else if (*str == '#')
		node->alternate = 1;
	else if (*str == '-')
		node->left_justified = 1;
}

void		check_flags(const char **str, t_struct *node)
{
	while (**str != '\0' && **str != '%')
	{
		if (**str == 's' || **str == 'c' || **str == 'd' || **str == 'o' ||
				**str == 'x' || **str == 'u' || **str == 'U' || **str == 'X' ||
				**str == 'O' || **str == 'D' || **str == 'p' || **str == 'C' ||
				**str == 'S' || **str == 'i')
			break ;
		if (**str != 'l' && **str != 'h' && **str != 'z' && **str != 'j' &&
				**str != '+' && **str != ' ' && **str != '0' && **str != '#' &&
				**str != '-' && (**str > 57 || **str < 48) && **str != '.')
			break ;
		part_check_flags(*str, node);
		if ((**str > 57 || **str <= 48) && **str != '.')
			(*str)++;
		if (**str <= 57 && **str > 48)
			node->width = ft_atoi_up(&str);
		if (**str == '.')
		{
			(*str)++;
			node->precision = ft_atoi_up(&str);
			node->dot = 1;
		}
	}
	node->type = **str;
}

static void	convert_2(t_struct *node)
{
	if (node->type == 'O')
	{
		node->type = 'o';
		node->l = 1;
	}
	else if (node->type == 'p')
	{
		node->type = 'x';
		node->alternate = 1;
		node->pointer = 1;
		node->l = 1;
	}
}

void		convert(t_struct *node)
{
	if (node->type == 'U')
	{
		node->type = 'u';
		node->l = 1;
	}
	else if (node->type == 'X')
	{
		node->type = 'x';
		node->upc = 1;
	}
	else if (node->type == 'D')
	{
		node->type = 'd';
		node->l = 1;
	}
	else
		convert_2(node);
}
