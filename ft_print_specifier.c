/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:45:41 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/13 11:39:45 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_specifier(va_list args, t_flags *flag, t_len *len)
{
	if (flag->chars == 'c')
		print_char(va_arg(args, int), flag, len);
	else if (flag->chars == 'i' || flag->chars == 'd')
		print_number(va_arg(args, int), flag, len);
	else if (flag->chars == 's')
		print_string(va_arg(args, char *), flag, len);
	else if (flag->chars == 'u')
		print_unsigned(va_arg(args, unsigned int), flag, len);
	else if (flag->chars == 'x' || flag->chars == 'X')
		print_hex(va_arg(args, unsigned int), flag, len);
	else if (flag->chars == 'p')
		print_pointer(va_arg(args, void *), flag, len);
	else if (flag->chars == '%')
		print_char('%', flag, len);
}
