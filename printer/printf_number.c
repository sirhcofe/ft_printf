/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:35 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/20 21:08:39 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	output = NULL;
	s_num = ft_itoa((long)n);
	if (ft_strlen(s_num) < (flag->nmbr_bfore_prcn)
		|| ft_strlen(s_num) < (flag->nmbr_after_prcn))
	{
		output = pregenerate_flag(flag);
		if (flag->minus != 0)
			ft_strlcpy(output, s_num, (ft_strlen(s_num) + 1));
		else
		{
			ft_strlcpy((output + ft_strlen(output) - ft_strlen(s_num)), s_num,
				(ft_strlen(s_num) + 1));
		}
		// free(s_num);
	}
	else
		output = ft_strdup(s_num);
	if (flag->plus != 0 || flag->blank != 0 || n < 0)
		output = fill_plus_blank(output, flag, n);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}
