/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 22:07:04 by jfinet            #+#    #+#             */
/*   Updated: 2018/08/29 22:08:45 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_one_byte(wchar_t value, t_struct *node)
{
	write(1, &value, 1);
	node->printed += 1;
}

void	put_two_bytes(wchar_t value, t_struct *node)
{
	unsigned char byte1;
	unsigned char byte2;

	byte1 = (unsigned char)(((value & 0x7C0) >> 6) + 0xC0);
	byte2 = (unsigned char)(((value & 0x3F)) + 0x80);
	write(1, &byte1, 1);
	write(1, &byte2, 1);
	node->printed += 2;
}

void	put_three_bytes(wchar_t value, t_struct *node)
{
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;

	byte1 = (unsigned char)(((value & 0xF000) >> 12) + 0xE0);
	byte2 = (unsigned char)(((value & 0xFC0) >> 6) + 0x80);
	byte3 = (unsigned char)(((value & 0x3F)) + 0x80);
	write(1, &byte1, 1);
	write(1, &byte2, 1);
	write(1, &byte3, 1);
	node->printed += 3;
}

void	put_four_bytes(wchar_t value, t_struct *node)
{
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;

	byte1 = (unsigned char)(((value & 0x1c0000) >> 18) + 0xF0);
	byte2 = (unsigned char)(((value & 0x3F000) >> 12) + 0x80);
	byte3 = (unsigned char)(((value & 0xFC0) >> 6) + 0x80);
	byte4 = (unsigned char)(((value & 0x3F)) + 0x80);
	write(1, &byte1, 1);
	write(1, &byte2, 1);
	write(1, &byte3, 1);
	write(1, &byte4, 1);
	node->printed += 4;
}
