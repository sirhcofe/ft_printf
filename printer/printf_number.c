/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:35 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/08 17:14:57 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// - s_num: converts number to string excluding '-' if it's negative
//   s_len: size of string including '-' sign if it's negative
// - to continue, we consider 2 situations:
//      1: the need to pregenerate spaces
//      2: no need to pregenerate
//   SITUATION 1:
//   - the condition to pregenerate is that either width or precision is bigger
//     than the size of the string, if true:
//          1.1: if width is bigger than prcn, pregenerate new string called
//               output with sizeof(width)
//          1.2: otherwise, pregenerate new string with sizeof(precision)
//   - once pregenerated, we need to consider 0 flag and precision flag unless
//     printf("%3.d", 0) or printf("%3.0d", 0), both flags put '0' to pregen str
//   - once fill_width_zero, fill in the numbers into pregen str
//   SITUATION 2:
//   - no need to pregenerate strings and fill zeros, just duplicate string to
//     new output string
// - problem with signs ('+' and '-') is that they are often appended at the
//   start of the string especially if the output string is '0' appended
//   example_1: printf("=%6d=", -123)  -> =  -123= 
//   example_2: printf("=%06d=", -123) -> =-00123=
//   example_3: printf("=%.6d=", -123) -> =-000123=
// - based on example above:
//   eg_1: no 0 flag or prcn, so append '-' before numbers
//   eg_2: 0 flag, so change output[0] to '-'
//   eg_3: prcn flag, so strjoin "-" and output (one byte bigger)
char	*continue_fn(char *output, int n, t_flags *flag)
{
	char	*s_num;
	int		s_len;

	s_num = ft_itoa((long)n);
	s_len = ft_strlen(s_num) + ((n < 0) * 1);
	if (flag->width >= s_len || flag->prcn >= s_len)
	{
		if (flag->width > flag->prcn)
			output = pregenerate_flag(flag, 1);
		else
			output = pregenerate_flag(flag, 2);
		if (!(flag->dot != 0 && flag->prcn == 0 && n == 0))
		{
			fill_width_zeros(output, flag);
			fill_numbr(output, s_num, flag);
		}
	}
	else
		output = ft_strdup(s_num);
	if ((flag->plus != 0 || flag->blank != 0) && n > 0)
		output = fill_plus_blank(output, flag, n);
	if (n < 0)
		output = fill_minus(output, flag, s_len);
	free(s_num);
	return (output);
}

// similar to print_unsigned and print_hex
void	print_number(int n, t_flags *flag, t_len *len)
{
	char	*output;

	output = NULL;
	if (flag->dot != 0 && flag->width == 0 && flag->prcn == 0 && n == 0)
		return ;
	output = continue_fn(output, n, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}
