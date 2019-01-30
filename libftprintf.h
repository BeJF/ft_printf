/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:48:57 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/06 20:12:32 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>

typedef struct	s_struct
{
	char		type;
	int			dot;
	int			precision;
	int			left_justified;
	int			width;
	int			alternate;
	int			padding;
	int			space;
	int			plus;
	char		sign;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			printed;
	int			upc;
	int			pointer;

}				t_struct;

uintmax_t		get_data_unsigned(va_list *pointer, t_struct *node);
void			get_deci(va_list *pointer, t_struct *node);
intmax_t		get_data_deci(va_list *pointer, t_struct *node);

int				check_sign_len(t_struct *node);
void			sign_handler(t_struct *node);

int				ft_printf(const char *restrict format, ...);
void			check_length(const char *str, t_struct *node);
void			check_flags(const char **str, t_struct *node);
void			convert(t_struct *node);

void			handle_zero_d(t_struct *node);
void			handle_zero_x(t_struct *node);
void			handle_zero_o(t_struct *node);

void			put_one_byte(wchar_t data, t_struct *node);
void			put_two_bytes(wchar_t data, t_struct *node);
void			put_three_bytes(wchar_t data, t_struct *node);
void			put_four_bytes(wchar_t data, t_struct *node);

void			ft_global_octa(va_list *pointer, t_struct *node);
void			ft_global_hexa(va_list *pointer, t_struct *node);
void			handle_unicode_str(va_list *pointer, t_struct *node);
void			handle_unicode_c(va_list *pointer, t_struct *node);

char			*precision_filter_d(char *data, t_struct *node);
char			*precision_filter_xo(char	*data, t_struct *node);
char			*precision_filter_str(char *data, int precision);

void			get_octa(va_list *pointer, t_struct *node);
void			get_hexa(va_list *pointer, t_struct *node);
void			get_str(va_list *pointer, t_struct *node);
void			get_char(va_list *pointer, t_struct *node);
void			get_unsigned(va_list *pointer, t_struct *node);
void			get_random(t_struct *node);

int				ft_atoi_up(const char ***str);
int				ft_strlen(const char *s);
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putstr_count(char const *s, t_struct *node);
void			ft_putchar_count(char c, t_struct *node);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strcat(char *s1, char const *s2);
char			*ft_itoa(uintmax_t data);
char			*ft_itoa_base(uintmax_t data, int base);
char			*ft_itoa_hexa(uintmax_t data, int upc);

#endif
