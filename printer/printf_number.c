/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:35 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/23 20:46:38 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	s_num = ft_itoa((long)n);
	if (flag->width > ft_strlen(s_num) || flag->precision > ft_strlen(s_num))
	{
		output = pregenerate_flag(flag);
		if (flag->precision > ft_strlen(s_num))
			fill_width_zeros(output, flag, flag->precision);
		else if (flag->zero != 0)
			fill_width_zeros(output, flag, ft_strlen(output));
		fill_chars(output, s_num, flag);
	}
	else
		output = ft_strdup(s_num);
	if (flag->plus != 0 || flag->blank != 0 || n > 0)
		output = fill_plus_blank(output, flag, n);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(s_num);
	free(output);
}
