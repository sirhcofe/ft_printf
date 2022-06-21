/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/21 18:44:10 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_char(int c, t_flags *flag, t_len *len)
{
	char	*output;
	int		i;

	output = pregenerate_flag(flag);
	if (output == NULL)
	{
		write(1, &c, 1);
		len->n += 1;
	}
	else
	{
		if (flag->minus != 0)
			output[0] = c;
		else
			output[flag->width - 1] = c;
		i = 0;
		while (i < flag->width)
			write(1, &output[i++], 1);
		len->n += (flag->width * 1);
		free(output);
	}
}
