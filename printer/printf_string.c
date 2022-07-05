/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:54:05 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/05 21:09:18 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	continue_fn(char *output, char *source, t_flags *flag, t_len *len)
{
	// printf("output:+%s+\n", output);
	if (!(flag->dot != 0 && flag->prcn == 0))
		fill_chars(output, source, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}

static void	print_string_w_dot(char *output, char *s, t_flags *flag, t_len *len)
{
	if (flag->width > ft_strlen(s) || (flag->width != 0 && flag->prcn == 0)
		|| (flag->width > flag->prcn && ft_strlen(s) > flag->prcn))
	{
		output = pregenerate_flag(flag, 1);
		continue_fn(output, s, flag, len);
	}
	else if (flag->width == 0 && flag->prcn == 0)
		return ;
	else if (ft_strlen(s) >= flag->width && ft_strlen(s) > flag->prcn)
	{
		output = pregenerate_flag(flag, 2);
		continue_fn(output, s, flag, len);
	}
	else if (ft_strlen(s) >= flag->width && flag->prcn >= ft_strlen(s))
	{
		ft_putstr_fd(s, 1);
		len->n += ft_strlen(s);
	}
}

void	print_string(char *s, t_flags *flag, t_len *len)
{
	char	*output;

	if (!s)
		print_string("(null)", flag, len);
	else if (flag->dot == 0)
	{
		if (flag->width != 0 && flag->width > ft_strlen(s))
		{
			output = pregenerate_flag(flag, 1);
			continue_fn(output, s, flag, len);
		}
		else
		{
			ft_putstr_fd(s, 1);
			len->n += ft_strlen(s);
		}
	}
	else
	{
		output = NULL;
		print_string_w_dot(output, s, flag, len);
	}
}
