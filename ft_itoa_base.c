/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:52:32 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 19:50:32 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_len_base(uintmax_t data, int base)
{
	int i;

	i = 1;
	while (data /= base)
		i++;
	return (i);
}

char		*ft_itoa_base(uintmax_t data, int base)
{
	int		len;
	char	*datastr;

	len = get_len_base(data, base);
	if (!(datastr = ft_strnew(len)))
		return (NULL);
	while (data)
	{
		datastr[--len] = data % base + '0';
		data /= base;
	}
	return (datastr);
}

char		*ft_itoa_hexa(uintmax_t data, int upc)
{
	int		len;
	char	*datastr;

	len = get_len_base(data, 16);
	if (!(datastr = ft_strnew(len)))
		return (NULL);
	while (data)
	{
		if (upc == 0)
		{
			if (data % 16 <= 9)
				datastr[--len] = data % 16 + '0';
			else
				datastr[--len] = data % 16 + 'a' - 10;
		}
		if (upc == 1)
		{
			if (data % 16 <= 9)
				datastr[--len] = data % 16 + '0';
			else
				datastr[--len] = data % 16 + 'A' - 10;
		}
		data /= 16;
	}
	return (datastr);
}
