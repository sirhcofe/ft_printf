/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:44 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/15 14:12:07 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// - fill chars from va_args(string)
// - this append the chars either from the right, or left
// - if append from left, considers '0' appended by prcn flag
//   example: printf("=-10.8x=", 12345678); -> =0001E240  =
//   from example above, the va_args(string) is not literally appended from left
void	fill_chars(char *output, char *src, t_flags *flag)
{
	if (flag->minus == 0)
		ft_strlcpy(output + ft_strlen(output) - ft_strlen(src), src,
			ft_strlen(src));
	else
	{
		if (flag->prcn <= ft_strlen(src))
			ft_strlcpy(output, src, ft_strlen(src));
		else if (flag->prcn > ft_strlen(src))
			ft_strlcpy(output + flag->prcn - ft_strlen(src), src,
				ft_strlen(src));
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
void	fill_strings(char *output, char *src, t_flags *flag)
{
	if (flag->width >= ft_strlen(src) && flag->width > flag->prcn
		&& flag->prcn == 0)
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src, ft_strlen(src));
		else
			ft_strlcpy(output + ft_strlen(output) - ft_strlen(src), src,
				ft_strlen(src));
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

// - extension of pregenerate_flag, and a modified version of calloc, in which
//   append spaces at every index up to null terminator
char	*ft_spalloc(int count, int size)
{
	char	*ptr;
	int		i;

	ptr = ft_calloc(count, size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < count)
	{
		ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

// - pregeneration of flags, which considers 2 condition
// - if width is bigger than strlen(va_argstr) and prcn, spalloc with size=width
//   elif prcn is bigger than strlen(va_argstr) and width, spalloc w size=prcn
char	*pregenerate_flag(t_flags *flag, int condition)
{
	char	*output;

	output = NULL;
	if (condition == 1)
		output = ft_spalloc(flag->width, sizeof(char));
	else if (condition == 2)
		output = ft_spalloc(flag->prcn, sizeof(char));
	return (output);
}
