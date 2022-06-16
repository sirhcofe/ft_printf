/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/16 22:42:15 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, t_flags *flag, t_len *len)
{
	char	*output;

	output = pregenerate_flag(flag);
	if (output == NULL)
		len->n += write(1, &c, 1);
	else
	{
		if (flag->minus != 0)
			output[0] = c;
		else
			output[ft_strlen(output)] = c;
		ft_putstr_fd(output, 1);
		len->n += ft_strlen(output);
		free(output);
	}

}
