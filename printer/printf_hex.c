/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:56:48 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/05 16:54:04 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// itoa, but for hex
void	ft_htoa(unsigned long n, char **s_hex, t_flags *flag)
{
	char	*s;

	if (n >= 16)
		ft_htoa((n / 16), s_hex, flag);
	n %= 16;
	s = ft_calloc(sizeof(char), 2);
	if (n >= 10 && n <= 15)
	{
		if (flag->chars == 'x')
			*s = (n - 10 + 'a');
		else if (flag->chars == 'X')
			*s = (n - 10 + 'A');
		*s_hex = ft_strjoin(*s_hex, s);
	}
	else
	{
		*s = n + '0';
		*s_hex = ft_strjoin(*s_hex, s);
	}
}

// - calls ft_htoa, but checks for hash flag
// - if true, appends 0x or 0X to front of string if specifier is 'x' or 'X'
//	 respectively
char	*hex_to_char(unsigned long n, t_flags *flag)
{
	char	*s_hex;

	s_hex = NULL;
	ft_htoa(n, &s_hex, flag);
	return (s_hex);
}

// - similar to print_number and print_unsigned
// (see printer/print_number.c for full explaination)
void	print_hex(unsigned long n, t_flags *flag, t_len *len)
{
	char	*s_hex;
	char	*output;

	s_hex = hex_to_char(n, flag);
	if (flag->width > ft_strlen(s_hex) || flag->prcn > ft_strlen(s_hex))
	{
		if (flag->width > ft_strlen(s_hex) && flag->width > flag->prcn)
			output = pregenerate_flag(flag, 1);
		else
			output = pregenerate_flag(flag, 2);
		fill_width_zeros(output, flag);
		fill_chars(output, s_hex, flag);
	}
	else
		output = ft_strdup(s_hex);
	if (flag->hash != 0)
		output = fill_hash_0x(output, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(s_hex);
	free(output);
}
