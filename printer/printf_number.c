/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:35 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/18 22:57:25 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// similar to print_unsigned and print_hex
// - converts number to string
// - before sending the output string to write, we consider 1 condition:
//	 - if sizeof(string) is shorter than nmbr_bfore_prcn, we append outputstring
//	   into pregenerated string, either left/right align based on minus flag
//	 - otherwise, we ignore the pregenerated string and send the output string
//	   to write function
void	print_number(int n, t_flags *flag, t_len *len)
{
	char	*s_num;
	char	*output;

	s_num = nmbr_to_str((long)n, flag);
	if (ft_strlen(s_num) < ft_atoi(flag->nmbr_bfore_prcn))
	{
		output = pregenerate_flag(flag);
		if (flag->minus != 0)
			ft_strlcpy(output, s_num, (ft_strlen(s_num) + 1));
		else
		{
			ft_strlcpy((output + ft_strlen(output) - ft_strlen(s_num)), s_num,
				(ft_strlen(s_num) + 1));
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
