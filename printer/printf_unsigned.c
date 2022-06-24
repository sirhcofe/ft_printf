/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:56:18 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/24 20:14:47 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// similar to print_number and print_hex
// (see printer/print_number.c for full explaination)
void	print_unsigned(unsigned int n, t_flags *flag, t_len *len)
{
	char	*s_num;
	char	*output;

	output = NULL;
	s_num = ft_itoa((long)n);
	if (flag->width > ft_strlen(s_num) || flag->precision > ft_strlen(s_num))
	{
		if (flag->width > ft_strlen(s_num) && flag->width > flag->precision)
			output = pregenerate_flag(flag, 1);
		else
			output = pregenerate_flag(flag, 2);
		fill_chars(output, s_num, flag);
	}
	else
		output = ft_strdup(s_num);
	if (flag->plus != 0 || flag->blank != 0 || n > 0)
		fill_plus_blank(output, flag, n);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(s_num);
	free(output);
}
