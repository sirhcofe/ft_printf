/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:56:48 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/15 13:49:21 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*hex_to_char(unsigned long n, t_flags *flag)
{
	char	*s_hex;

	s_hex = NULL;
	ft_htoa(n, &s_hex, flag);
	return (s_hex);
}

char	*continue_hex(char *output, unsigned long n, t_flags *flag)
{
	char	*s_hex;

	s_hex = hex_to_char(n, flag);
	if (flag->width >= ft_strlen(s_hex) || flag->prcn >= ft_strlen(s_hex))
	{
		if (flag->width > flag->prcn)
			output = pregenerate_flag(flag, 1);
		else
			output = pregenerate_flag(flag, 2);
		if (!(flag->dot != 0 && flag->prcn == 0 && n == 0))
		{
			fill_width_zeros(output, flag);
			fill_chars(output, s_hex, flag);
		}
	}
	else
		output = ft_strdup(s_hex);
	if (flag->hash != 0 && n != 0)
		output = fill_hash_0x(output, flag);
	free(s_hex);
	return (output);
}

// - technically similar to printf_number, except instead of converting number
//   to char, we need to convert number to hex before converting to char
// - (read printf_number for detailed explaination)
// - for printf_hex, we do not need to consider ' ' flag or '+' flag, but we
//   do however need to consider '#' flag
//   And the '#' flag will be ignored if n == 0
//   example: ft_printf("=%#x=", 123) -> =0x7b=
//            ft_printf("=%#x=", 0)   -> =0=
//            ft_printf("=%#x=", 1)   -> =0x1=
void	print_hex(unsigned long n, t_flags *flag, t_len *len)
{
	char	*output;

	output = NULL;
	if (flag->dot != 0 && flag->width == 0 && flag->prcn == 0 && n == 0)
		return ;
	output = continue_hex(output, n, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}
