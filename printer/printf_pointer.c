/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:57:13 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/13 11:40:04 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*continue_ptr(char *output, unsigned long lu_ptr, t_flags *flag)
{
	char			*s_ptr;

	s_ptr = hex_to_char(lu_ptr, flag);
	if (flag->width >= ft_strlen(s_ptr) || flag->prcn >= ft_strlen(s_ptr))
	{
		if (flag->width > flag->prcn)
			output = pregenerate_flag(flag, 1);
		else
			output = pregenerate_flag(flag, 2);
		if (!(flag->dot != 0 && flag->prcn == 0 && lu_ptr == 0))
		{
			fill_width_zeros(output, flag);
			fill_chars(output, s_ptr, flag);
		}
	}
	else
		output = ft_strdup(s_ptr);
	output = fill_hash_0x(output, flag);
	free(s_ptr);
	return (output);
}

// - technically the same as printf_hex, however we will always need to append
//   "0x" before the hex (unlike printf_hex which will only do so with '#' flag)
//   and "0x" will print regardless of any hex value, even 0
//   example: (hex) ft_printf("=%#x=", 0)  -> =0=
//            (ptr) ft_printf("=%p=", 0)   -> =0x0=
void	print_pointer(void *ptr, t_flags *flag, t_len *len)
{
	unsigned long	lu_ptr;
	char			*output;

	output = NULL;
	flag->chars = 'x';
	lu_ptr = (unsigned long)ptr;
	if (flag->dot != 0 && flag->width == 0 && flag->prcn == 0 && lu_ptr == 0)
		return ;
	output = continue_ptr(output, lu_ptr, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}
