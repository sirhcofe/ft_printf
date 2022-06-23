/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/23 18:50:50 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_char(int c, t_flags *flag, t_len *len)
{
	char	*output;
	int		i;

	if (flag->width != 0)
	{
		output = pregenerate_flag(flag);
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
