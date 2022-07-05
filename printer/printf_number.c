/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:35 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/05 21:33:01 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	continue_fn(char *output, int n, t_flags *flag, t_len *len)
{
	if ((flag->plus != 0 || flag->blank != 0) && n > 0)
		output = fill_plus_blank(output, flag, n);
	if (n < 0)
		output = fill_minus(output, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}

// similar to print_unsigned and print_hex
// - converts number to string
// - before sending the output string to write, we consider 1 condition:
//	 - if sizeof(string) is shorter than width, we append outputstring
//	   into pregenerated string, either left/right align based on minus flag
//	 - otherwise, we ignore the pregenerated string and send the output string
//	   to write function
void	print_number(int n, t_flags *flag, t_len *len)
{
	char	*s_num;
	char	*output;

	output = NULL;
	if (flag->dot != 0 && flag->width == 0 && flag->prcn == 0 && n == 0)
		return ;
	s_num = ft_itoa((long)n);
	if (flag->width > ft_strlen(s_num) || flag->prcn > ft_strlen(s_num))
	{
		if (flag->width > ft_strlen(s_num) && flag->width > flag->prcn)
			output = pregenerate_flag(flag, 1);
		else
			output = pregenerate_flag(flag, 2);
		fill_width_zeros(output, flag);
		fill_chars(output, s_num, flag);
	}
	else
		output = ft_strdup(s_num);
	continue_fn(output, n, flag, len);
	free(s_num);
}
