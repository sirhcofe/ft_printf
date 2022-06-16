/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:45:41 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/16 21:32:41 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_specifier(va_list args, t_flags *flag, t_len *len)
{
	int	i;

	i = -1;
	while (flag->flag_str[++i])
	{
		if (flag->flag_str[i] == 'c')
			print_char(va_arg(args, int), flag, len);
		else if (flag->flag_str[i] == 'i' || flag->flag_str[i] == 'd')
			print_number(va_arg(args, int), flag, len);
		else if (flag->flag_str[i] == 's')
			print_string(va_arg(args, char *), flag, len);
		else if (flag->flag_str[i] == 'u')
			print_unsigned(va_arg(args, unsigned int), flag, len);
		else if (flag->flag_str[i] == 'x' || flag->flag_str[i] == 'X')
			print_hex(va_arg(args, unsigned int), flag, len);
		else if (flag->flag_str[i] == 'p')
			print_pointer(va_arg(args, void *), flag, len);
		else if (flag->flag_str[i] == '%')
			print_char('%', flag, len);
	}
}
