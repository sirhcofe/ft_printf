/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:54:05 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/19 19:00:33 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *s, t_flags *flag, t_len *len)
{
	char	*output;

	if (!s)
		print_string("(null)", flag, len);
	else if (ft_strlen(s) < (flag->nmbr_bfore_prcn))
	{
		output = pregenerate_flag(flag);
		if (flag->minus != 0)
			ft_strlcpy(output, s, (flag->nmbr_bfore_prcn));
		else
		{
			ft_strlcpy((output + ft_strlen(output) - ft_strlen(s)), s,
				(ft_strlen(s) + 1));
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
