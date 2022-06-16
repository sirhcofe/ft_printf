/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:54:05 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/16 20:55:49 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *s, t_flags *flag, t_len *len)
{
	char	*output;

	if (!s)
		print_string("(null)", flag, len);
	if (ft_strlen(s) < ft_atoi(flag->nmbr_bfore_prcn))
	{
		output = pregenerate_flag(flag);
		if (flag->minus != 0)
			ft_strlcpy(output, s, ft_strlen(s));
		else
		{
			ft_strlcpy((output + ft_strlen(output) - ft_strlen(s)), s,
				ft_strlen(s));
		}
		ft_putstr_fd(output, 1);
		len->n += ft_strlen(output);
		free(output);
	}
	else
	{
		ft_putstr_fd(s, 1);
		len->n += ft_strlen(s);
	}
}
