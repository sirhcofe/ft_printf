/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/13 11:17:00 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// - easiest specifier to deal with :')
// - pregenerate string if width exist
//     example: ft_printf("=%10c=")
//   then conisder '-' flag which if true will append char(c) from left instead
//   of from right
//     example: ft_printf("=%-10c=", 'c') -> =c         =
//              ft_printf("=%10c=", 'c')  -> =         c=
// - otherwise, just write
//     example: ft_printf("=%c=")
void	print_char(int c, t_flags *flag, t_len *len)
{
	char	*output;
	int		i;

	i = 0;
	if (flag->width != 0)
	{
		output = pregenerate_flag(flag, 1);
		if (flag->minus != 0)
			output[0] = c;
		else
			output[flag->width - 1] = c;
		while (i < flag->width)
			write(1, &output[i++], 1);
		len->n += flag->width;
		free(output);
	}
	else
	{
		write(1, &c, 1);
		len->n += 1;
	}
}
