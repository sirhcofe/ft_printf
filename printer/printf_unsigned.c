/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:56:18 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/19 19:00:33 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// similar to print_number and print_hex
// (see printer/print_number.c for full explaination)
void	print_unsigned(unsigned int n, t_flags *flag, t_len *len)
{
	char	*s_num;
	char	*output;

	s_num = ft_itoa((long)n);
	if (ft_strlen(s_num) < (flag->nmbr_bfore_prcn))
	{
		output = pregenerate_flag(flag);
		if (flag->minus != 0)
			ft_strlcpy(output, s_num, ft_strlen(s_num));
		else
		{
			ft_strlcpy((output + ft_strlen(output) - ft_strlen(s_num)), s_num,
				ft_strlen(s_num));
		}
		ft_putstr_fd(output, 1);
		len->n += ft_strlen(output);
		free(output);
	}
	else
	{
		ft_putstr_fd(s_num, 1);
		len->n += ft_strlen(s_num);
	}
	free(s_num);
}
