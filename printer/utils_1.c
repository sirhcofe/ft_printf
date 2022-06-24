/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:44 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/24 22:52:34 by chenlee          ###   ########.fr       */
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

char	*pregenerate_flag(t_flags *flag, int condition)
{
	char	*output;

	output = NULL;
	if (condition == 1)
		output = ft_spalloc(flag->width, sizeof(char));
	else if (condition == 2)
		output = ft_spalloc(flag->precision, sizeof(char));
	return (output);
}
