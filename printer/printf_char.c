/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/20 21:26:06 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_char(int c, t_flags *flag, t_len *len)
{
	char	*output;

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
			output[ft_strlen(output) - 1] = c;
		ft_putstr_fd(output, 1);
		len->n += ft_strlen(output);
		free(output);
	}
}
