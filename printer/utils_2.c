/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:26 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/07 18:16:53 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	fill_numbr(char *output, char *src, t_flags *flag)
{
	if (!(flag->dot != 0 && flag->prcn == 0))
	{
		if (flag->minus == 0)
			ft_strlcpy(output + ft_strlen(output) - ft_strlen(src), src,
				ft_strlen(src));
		else
		{
			if (flag->prcn <= ft_strlen(src))
				ft_strlcpy(output, src, ft_strlen(src) + 1);
			else if (flag->prcn > ft_strlen(src))
				ft_strlcpy(output + flag->prcn - ft_strlen(src), src,
					ft_strlen(src));
		}
	}
}

// append chars into pregenerated string
// 1st nested-if considers any specifiers except 's' or 's' without precision
// 2nd nested-if considers the rest of 's' condition:
//		- 1st if: to append from left
//		- 2nd if: to append from right
//		in which for 2nd nested-if, both if cases the functions only copy format
//		string up to either ft_strlen(source) or flag->prcn whichever is bigger
// have a stroke reading this :)
void	fill_chars(char *output, char *src, t_flags *flag)
{
	if (flag->width > ft_strlen(src) && flag->width > flag->prcn
			&& flag->prcn == 0)
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src, (ft_strlen(src) + 1));
		else
			ft_strlcpy(output + ft_strlen(output) - ft_strlen(src), src,
				ft_strlen(src) + 1);
	}
	else
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src,
				((ft_strlen(src) >= flag->prcn) * (flag->prcn)
					+ (flag->prcn > ft_strlen(src))
					* (ft_strlen(src))));
		else
			ft_strlcpy(output + ft_strlen(output) - ((flag->prcn
						>= ft_strlen(src)) * ft_strlen(src) + (ft_strlen(src)
						> flag->prcn) * flag->prcn), src,
				((flag->prcn >= ft_strlen(src)) * ft_strlen(src)
					+ (ft_strlen(src) > flag->prcn) * flag->prcn));
	}
}

// to fill the spaces with 0 when zero flag or number_after_prcn is used
void	fill_width_zeros(char *output, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->prcn != 0)
	{
		if (flag->minus != 0)
		{
			while (i < (flag->prcn))
				output[i++] = '0';
		}
		else
		{
			i = 1;
			while (i < (flag->prcn + 1))
				output[ft_strlen(output) - i++] = '0';
		}
	}
	else if (flag->zero != 0)
	{
		while (i < ft_strlen(output))
			output[i++] = '0';
	}
}
