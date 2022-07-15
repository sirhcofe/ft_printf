/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:01:54 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/15 12:11:39 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// - it's the same as print_char, but we need to consider extra '0' flag
//   so extra if statement on line 26-27
void	print_percent(char c, t_flags *flag, t_len *len)
{
	char	*output;
	int		i;

	i = 0;
	if (flag->width != 0)
	{
		output = pregenerate_flag(flag, 1);
		if (flag->zero != 0)
			fill_width_zeros(output, flag);
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
