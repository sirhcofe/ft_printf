/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:54:05 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/03 18:01:36 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	continue_fn(char *output, char *source, t_flags *flag, t_len *len)
{
	fill_chars(output, source, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}

// first if:  if format string is null, print "(null)"
// second if: for ft_printf("-%s-", "abcde");    -> -abcde-
//                ft_printf("-%2.9s-", "abcde"); -> -abcde-
//                ft_printf("-%1s-", "abcde");   -> -abcde-
// third if: for ft_printf("-%10s-", "abcde");  -> -     abcde-
//               ft_printf("-%4.2s-", "abcde"); -> -  ab-
// fourth if:  for ft_printf("-%2.4s-", "abcde"); -> -abcd-

void	print_string(char *s, t_flags *flag, t_len *len)
{
	char	*output;

	if (!s)
		print_string("(null)", flag, len);
	else if ((flag->width == 0 && flag->precision == 0)
		|| (flag->width < ft_strlen(s) && flag->precision > ft_strlen(s))
		|| (flag->width < ft_strlen(s) && flag->precision == 0))
	{
		ft_putstr_fd(s, 1);
		len->n += ft_strlen(s);
	}
	else if (flag->width > ft_strlen(s)
		|| (flag->width > flag->precision && flag->precision < ft_strlen(s)))
	{
		output = pregenerate_flag(flag, 1);
		continue_fn(output, s, flag, len);
	}
	else if (flag->width < flag->precision && flag->precision < ft_strlen(s))
	{
		output = pregenerate_flag(flag, 2);
		continue_fn(output, s, flag, len);
	}
}
