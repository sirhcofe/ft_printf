/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:56:18 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/13 11:40:08 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	continue_uint(char *output, unsigned int n, t_flags *flag, t_len *len)
{
	if ((flag->plus != 0 || flag->blank != 0) && n > 0)
		output = fill_plus_blank(output, flag, n);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}

// similar to print_number and print_hex
// (see printer/print_number.c for full explaination)
void	print_unsigned(unsigned int n, t_flags *flag, t_len *len)
{
	char	*s_num;
	char	*output;

	output = NULL;
	if (flag->dot != 0 && flag->width == 0 && flag->prcn == 0 && n == 0)
		return ;
	s_num = ft_itoa((long)n);
	if (flag->width >= ft_strlen(s_num) || flag->prcn >= ft_strlen(s_num))
	{
		if (flag->width > flag->prcn)
			output = pregenerate_flag(flag, 1);
		else
			output = pregenerate_flag(flag, 2);
		if (!(flag->dot != 0 && flag->prcn == 0 && n == 0))
		{
			fill_width_zeros(output, flag);
			fill_chars(output, s_num, flag);
		}
	}
	else
		output = ft_strdup(s_num);
	continue_uint(output, n, flag, len);
	free(s_num);
}
