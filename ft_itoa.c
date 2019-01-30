/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:34:23 by jfinet            #+#    #+#             */
/*   Updated: 2018/08/27 20:38:39 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static intmax_t		ft_get_len(uintmax_t n)
{
	intmax_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(uintmax_t n)
{
	intmax_t		c;
	char			*tab;

	c = ft_get_len(n);
	if (!(tab = ft_strnew(c)))
		return (NULL);
	tab[--c] = n % 10 + '0';
	while (n /= 10)
		tab[--c] = n % 10 + '0';
	return (tab);
}
