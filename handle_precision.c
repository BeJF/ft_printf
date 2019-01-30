/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:38:24 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 20:04:59 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*precision_filter_str(char *data, int precision)
{
	int		len;
	int		diff;
	int		i;
	char	*precidata;

	i = 0;
	len = ft_strlen(data);
	if (precision >= len)
		return (data);
	if (!(precidata = ft_strnew(precision)))
		return (NULL);
	while (precision-- != 0)
	{
		precidata[i++] = *data;
		data++;
	}
	return (precidata);
}

static char	*handle_alternate(t_struct *node, char *data)
{
	char	*tab;
	char	*tabfinal;

	if (node->alternate == 0)
		return (data);
	if (node->type == 'x')
	{
		tab = ft_strnew(2);
		tab[0] = '0';
		tab[1] = (node->upc == 1) ? 'X' : 'x';
	}
	if (node->type == 'o')
	{
		tab = ft_strnew(1);
		tab[0] = '0';
	}
	tabfinal = ft_strjoin_free(tab, data);
	return (tabfinal);
}

char		*precision_filter_xo(char *data, t_struct *node)
{
	int		diff;
	int		i;
	int		precision;
	char	*precidata;

	i = 0;
	precision = node->precision;
	if (precision <= ft_strlen(data))
	{
		data = handle_alternate(node, data);
		return (data);
	}
	diff = precision - ft_strlen(data);
	precidata = ft_strnew(precision);
	while (i < diff)
		precidata[i++] = '0';
	while (precision-- != 0 && *data)
	{
		precidata[i++] = *data;
		data++;
	}
	if (node->type == 'x')
		precidata = handle_alternate(node, precidata);
	return (precidata);
}

char		*precision_filter_d(char *data, t_struct *node)
{
	int		len;
	int		diff;
	int		i;
	int		precision;
	char	*precidata;

	precision = node->precision;
	len = ft_strlen(data);
	if (precision <= len)
		return (data);
	diff = precision - len;
	i = 0;
	if (!(precidata = ft_strnew(precision)))
		return (NULL);
	while (i < diff)
		precidata[i++] = '0';
	while (precision-- != 0 && *data)
	{
		precidata[i++] = *data;
		data++;
	}
	return (precidata);
}
