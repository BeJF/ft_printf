/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:16:27 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 16:51:37 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *tab;

	if (!s1 || !s2)
		return (0);
	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (tab == NULL)
		return (NULL);
	tab = ft_strcat(tab, s1);
	tab = ft_strcat(tab, s2);
	free(s1);
	free(s2);
	return (tab);
}
