/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:44 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/21 20:21:57 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// initial allocation of spaces based on number_before_precision
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

// to fill the spaces with 0 when zero flag or number_after_precision is used
void	fill_width(char *output, t_flags *flag, int n)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(output) - 1;
	if (flag->minus != 0)
	{
		while (i <= n)
		{
			output[i] = '0';
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			output[j] = '0';
			i++;
			j--;
		}
	}
}

// ----- pregeneration of string -----
// line 80-88: if statement tries to allocate spaces if there's width;
// 			   however if we are printing numbers, we need to consider if
//			   ( precision > width) in which if true, we will
//			   instead allocate spaces based on  precision
// line 89-95: if there is a zero flag, fill_width spaces with 0
//			   if ( precision != NULL), fill_width  precision of 0
char	*pregenerate_flag(t_flags *flag)
{
	char	*output;

	output = NULL;
	if (flag->width > 0)
	{
		if (flag-> precision > flag->width)
			output = ft_spalloc(flag-> precision, sizeof(char));
		else
			output = ft_spalloc(flag->width, sizeof(char));
	}
	if (ft_strchr("cs%", flag->chars) == 0)
	{
		if (flag-> precision > 0)
			fill_width(output, flag, (flag-> precision));
		else if (flag->zero != 0)
			fill_width(output, flag, (flag->width));
	}
	return (output);
}
