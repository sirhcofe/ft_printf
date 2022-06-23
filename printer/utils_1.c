/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:44 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/23 18:50:09 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (flag->precision > flag->width)
			output = ft_spalloc(flag-> precision, sizeof(char));
		else
			output = ft_spalloc(flag->width, sizeof(char));
	}
	return (output);
}
